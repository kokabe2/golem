// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "sleep_command.h"

#include <stdbool.h>

#include "bleu/v1/heap.h"
#include "command_private.h"
#include "malkt/v1/time_unit.h"

typedef struct {
  CommandStruct base;
  int sleep_time;
  ActiveObjectEngine engine;
  Command wakeup_command;
  bool started;
  int64_t start_time;
} SleepCommandStruct, *SleepCommand;

static void Delete(Command *self) { heap->Delete((void **)self); }

inline static bool ShouldWakeUp(SleepCommand self, int64_t current_time) {
  return (current_time - self->start_time) >= self->sleep_time;
}

static void Do(Command base) {
  int64_t current_time = timeUnit->Now(timeUnit->Millisecond);
  SleepCommand self = (SleepCommand)base;
  if (!self->started) {
    self->started = true;
    self->start_time = current_time;
    activeObjectEngine->AddCommand(self->engine, base);
  } else if (ShouldWakeUp(self, current_time)) {
    activeObjectEngine->AddCommand(self->engine, self->wakeup_command);
  } else {
    activeObjectEngine->AddCommand(self->engine, base);
  }
}

static const CommandInterfaceStruct kTheInterface = {
    .Delete = Delete, .Do = Do,
};

static Command New(int milliseconds, ActiveObjectEngine engine, Command wakeup_command) {
  SleepCommand self = (SleepCommand)heap->New(sizeof(SleepCommandStruct));
  self->base.impl = &kTheInterface;
  self->sleep_time = milliseconds;
  self->engine = engine;
  self->wakeup_command = wakeup_command;
  return (Command)self;
}

static const SleepCommandMethodStruct kTheMethod = {
    .New = New,
};

const SleepCommandMethod sleepCommand = &kTheMethod;
