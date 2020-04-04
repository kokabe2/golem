// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "error_command.h"

#include "bleu/v1/heap.h"

typedef struct {
  CommandInterfaceStruct impl;
  NotifyDelegate Notify;
  const char *message;
  int error;
  int parameter;
} ErrorCommandStruct, *ErrorCommand;

static void Delete(Command *self) { heap->Delete((void **)self); }

static void Do(Command base) {
  ErrorCommand self = (ErrorCommand)base;
  self->Notify(self->message, self->error, self->parameter);
}

static const CommandInterfaceStruct kTheInterface = {
    .Delete = Delete,
    .Do = Do,
};

static Command New(NotifyDelegate delegate) {
  ErrorCommand self = (ErrorCommand)heap->New(sizeof(ErrorCommandStruct));
  self->impl = kTheInterface;
  self->Notify = delegate;
  return (Command)self;
}

static void SetErrorInfo(Command base, const char *message, int error, int parameter) {
  ErrorCommand self = (ErrorCommand)base;
  self->message = message;
  self->error = error;
  self->parameter = parameter;
}

static const ErrorCommandMethodStruct kTheMethod = {
    .New = New,
    .SetErrorInfo = SetErrorInfo,
};

const ErrorCommandMethod errorCommand = &kTheMethod;
