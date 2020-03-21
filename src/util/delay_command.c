// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "delay_command.h"

#include "bleu/v1/heap.h"
#include "command_protected.h"
#include "malkt/v1/task.h"

typedef struct {
  CommandStruct base;
  int delay_time;
} DelayCommandStruct, *DelayCommand;

inline static DelayCommand Downcast(Command self) { return (DelayCommand)self; }

static void Delete(Command *self) { heap->Delete((void **)self); }

static void Do(Command self) { task->Delay(Downcast(self)->delay_time); }

static const CommandAbstractMethodStruct kConcreteMethod = {
    .Delete = Delete,
    .Do = Do,
};

static Command New(int milliseconds) {
  Command self = (Command)heap->New(sizeof(DelayCommandStruct));
  self->impl = &kConcreteMethod;
  Downcast(self)->delay_time = milliseconds;
  return self;
}

static int GetDelayTime(Command self) { return Downcast(self)->delay_time; }

static void SetDelayTime(Command self, int milliseconds) { Downcast(self)->delay_time = milliseconds; }

static const DelayCommandMethodStruct kTheMethod = {
    .New = New,
    .GetDelayTime = GetDelayTime,
    .SetDelayTime = SetDelayTime,
};

const DelayCommandMethod delayCommand = &kTheMethod;
