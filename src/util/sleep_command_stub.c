// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "command_protected.h"
#include "sleep_command.h"

typedef struct {
  CommandStruct base;
  Command wakeup_command;
} SleepCommandStruct, *SleepCommand;

static SleepCommandStruct the_instance;

static void Delete(Command *self) {}

static void Do(Command self) { the_instance.wakeup_command->impl->Do(self); }

static void Cancel(Command self) {}

static const CommandAbstractMethodStruct kConcreteMethod = {
    .Delete = Delete,
    .Do = Do,
    .Cancel = Cancel,
};

static Command New(int milliseconds, ActiveObjectEngine engine, Command wakeup_command) {
  the_instance.base.impl = &kConcreteMethod;
  the_instance.wakeup_command = wakeup_command;
  return &the_instance;
}

static int GetSleepTime(Command self) {}

static void SetSleepTime(Command self, int milliseconds) {}

static const SleepCommandMethodStruct kTheMethod = {
    .New = New,
    .GetSleepTime = GetSleepTime,
    .SetSleepTime = SetSleepTime,
};

const SleepCommandMethod sleepCommand = &kTheMethod;
