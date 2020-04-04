// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "counting_command_stub.h"

#include "bleu/v1/heap.h"
#include "command_private.h"

typedef struct {
  CommandStruct base;
  int count;
} CountingCommandStubStruct, *CountingCommandStub;

static void Delete(Command *self) { heap->Delete((void **)self); }

static void Do(Command base) {
  CountingCommandStub self = (CountingCommandStub)base;
  ++self->count;
}

static const CommandInterfaceStruct kTheInterface = {
    .Delete = Delete,
    .Do = Do,
};

static Command New(void) {
  CountingCommandStub self = (CountingCommandStub)heap->New(sizeof(CountingCommandStubStruct));
  self->base.impl = &kTheInterface;
  return (Command)self;
}

static int Count(Command base) {
  CountingCommandStub self = (CountingCommandStub)base;
  return self->count;
}

static const CountingCommandStubMethodStruct kTheMethod = {
    .New = New,
    .Count = Count,
};

const CountingCommandStubMethod countingCommandStub = &kTheMethod;
