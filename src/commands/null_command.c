// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "null_command.h"

#include <stddef.h>

static Command the_instance = NULL;

static void Delete(Command *self) {}

static void Do(Command self) {}

static const CommandInterfaceStruct kTheInterface = {
    .Delete = Delete,
    .Do = Do,
};

static Command New(void) { return (Command)&kTheInterface; }

static Command GetInstance(void) {
  if (the_instance == NULL) the_instance = New();
  return the_instance;
}

static const NullCommandMethodStruct kTheMethod = {
    .GetInstance = GetInstance,
};

const NullCommandMethod nullCommand = &kTheMethod;
