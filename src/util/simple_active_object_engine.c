// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "simple_active_object_engine.h"

#include <stddef.h>

#include "active_object_engine_private.h"
#include "bleu/v1/heap.h"
#include "bleu/v1/list.h"

typedef struct {
  ActiveObjectEngineStruct base;
  List commands;
} SimpleActiveObjectEngineStruct, *SimpleActiveObjectEngine;

static void Delete(ActiveObjectEngine* base) {
  SimpleActiveObjectEngine self = (SimpleActiveObjectEngine)*base;
  list->Delete(&self->commands);
  heap->Delete((void**)base);
}

static void Run(ActiveObjectEngine base) {
  SimpleActiveObjectEngine self = (SimpleActiveObjectEngine)base;
  Command c;
  while ((c = list->Pop(self->commands, 0)) != NULL) command->Do(c);
}

static void AddCommand(ActiveObjectEngine base, Command c) {
  SimpleActiveObjectEngine self = (SimpleActiveObjectEngine)base;
  list->Add(self->commands, c);
}

static const ActiveObjectEngineInterfaceStruct kTheInterface = {
    .Delete = Delete, .Run = Run, .AddCommand = AddCommand,
};

static ActiveObjectEngine New(void) {
  SimpleActiveObjectEngine self = (SimpleActiveObjectEngine)heap->New(sizeof(SimpleActiveObjectEngineStruct));
  self->base.impl = &kTheInterface;
  self->commands = list->New();
  return (ActiveObjectEngine)self;
}

static const SimpleActiveObjectEngineMethodStruct kTheMethod = {
    .New = New,
};

const SimpleActiveObjectEngineMethod simpleActiveObjectEngine = &kTheMethod;
