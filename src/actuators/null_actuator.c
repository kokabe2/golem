// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "null_actuator.h"

#include <stddef.h>

#include "null_command.h"

static Component the_instance = NULL;

static void Delete(Component* self) {}

static int NonsenseValue(Component self) { return ~0; }

static const char* EmptyString(Component self) { return ""; }

static bool False(Component self) { return false; }

static Command NullCommand(Component self) { return nullCommand->GetInstance(); }

static const ActuatorInterfaceStruct kTheInterface = {
    .Delete = Delete,
    .Id = NonsenseValue,
    .Tag = EmptyString,
    .State = EmptyString,
    .IsOn = False,
    .ActuatorOnCommand = NullCommand,
    .ActuatorOffCommand = NullCommand,
    .ActuatorForceOffCommand = NullCommand,
};

inline static Component New(void) { return (Component)&kTheInterface; }

static Component GetInstance(void) {
  if (the_instance == NULL) the_instance = New();
  return the_instance;
}

static const NullActuatorMethodStruct kTheMethod = {
    .GetInstance = GetInstance,
};

const NullActuatorMethod nullActuator = &kTheMethod;
