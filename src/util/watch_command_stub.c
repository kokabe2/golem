// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "command_protected.h"
#include "watch_command.h"

typedef struct {
  CommandStruct base;
  Command notification_command;
} WatchCommandStruct, *WatchCommand;

static WatchCommandStruct the_instance;

static void Delete(Command *self) {}

static void Do(Command self) { the_instance.notification_command->impl->Do(self); }

static void Cancel(Command self) {}

static const CommandAbstractMethodStruct kConcreteMethod = {
    .Delete = Delete,
    .Do = Do,
    .Cancel = Cancel,
};

static Command New(WatchCommandObserverDelegate observer, ActiveObjectEngine engine, Command notification_command) {
  the_instance.base.impl = &kConcreteMethod;
  the_instance.notification_command = notification_command;
  return &the_instance;
}

static void SetTimeout(Command self, int milliseconds, Command timeout_command) {}

static const WatchCommandMethodStruct kTheMethod = {
    .New = New,
    .SetTimeout = SetTimeout,
};

const WatchCommandMethod watchCommand = &kTheMethod;
