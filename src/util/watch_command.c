// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "watch_command.h"

#include <stdbool.h>
#include <stddef.h>

#include "bleu/v1/heap.h"
#include "command_protected.h"
#include "malkt/v1/uptime.h"

typedef enum {
  kNone = 0,
  kCancel,
  kDelete,
} PrivateRequest;

typedef struct {
  CommandStruct base;
  int timeout;
  uint64_t start_time;
  bool started;
  PrivateRequest request;
  ActiveObjectEngine engine;
  WatchCommandObserverDelegate observer;
  Command notification_command;
  Command timeout_command;
} WatchCommandStruct, *WatchCommand;

inline static WatchCommand Downcast(Command self) { return (WatchCommand)self; }

static void Delete(Command *self) {
  if (Downcast(*self)->started) {
    Downcast(*self)->request = kDelete;
    *self = NULL;
  } else {
    heap->Delete((void **)self);
  }
}

inline static bool HasRequest(WatchCommand self) { return self->request != kNone; }

static void ProcessRequest(WatchCommand self) {
  switch (self->request) {
    case kNone:
      break;
    case kCancel:
      self->started = false;
      self->request = kNone;
      break;
    case kDelete:
      heap->Delete((void **)&self);
  }
}

inline static bool ShouldNotify(WatchCommand self) { return self->observer(); }

inline static bool IsTimeout(WatchCommand self, uint64_t current_time) {
  return self->timeout != 0 && (current_time - self->start_time) >= self->timeout;
}

static void Do(Command self) {
  uint64_t current_time = uptime->Get();
  WatchCommand wc = Downcast(self);
  if (HasRequest(wc)) {
    ProcessRequest(wc);
  } else if (ShouldNotify(wc)) {
    activeObjectEngine->AddCommand(wc->engine, wc->notification_command);
  } else if (!wc->started) {
    wc->started = true;
    wc->start_time = current_time;
    activeObjectEngine->AddCommand(wc->engine, self);
  } else if (IsTimeout(wc, current_time)) {
    activeObjectEngine->AddCommand(wc->engine, wc->timeout_command);
  } else {
    activeObjectEngine->AddCommand(wc->engine, self);
  }
}

static void Cancel(Command self) { Downcast(self)->request = kCancel; }

static const CommandAbstractMethodStruct kConcreteMethod = {
    .Delete = Delete,
    .Do = Do,
    .Cancel = Cancel,
};

static Command New(WatchCommandObserverDelegate observer, ActiveObjectEngine engine, Command notification_command) {
  Command self = (Command)heap->New(sizeof(WatchCommandStruct));
  self->impl = &kConcreteMethod;
  Downcast(self)->observer = observer;
  Downcast(self)->engine = engine;
  Downcast(self)->notification_command = notification_command;
  return self;
}

static void SetTimeout(Command self, int milliseconds, Command timeout_command) {
  Downcast(self)->timeout = milliseconds;
  Downcast(self)->timeout_command = timeout_command;
}

static const WatchCommandMethodStruct kTheMethod = {
    .New = New,
    .SetTimeout = SetTimeout,
};

const WatchCommandMethod watchCommand = &kTheMethod;
