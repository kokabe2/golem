// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "null_actuator.h"

#include <stddef.h>

#include "actuator_private.h"
#include "null_command.h"

static ActuatorStruct the_singleton;
static Actuator the_instance = NULL;

static void Delete(Actuator* self) {}

static int NonsenseValue(Actuator self) { return ~0; }

static const char* EmptyString(Actuator self) { return ""; }

static bool False(Actuator self) { return false; }

static Command NullCommand(Actuator self) { return nullCommand->GetInstance(); }

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

inline static Actuator New(void) {
  the_singleton.impl = &kTheInterface;
  return &the_singleton;
}

static Actuator GetInstance(void) {
  if (the_instance == NULL) the_instance = New();
  return the_instance;
}

static const NullActuatorMethodStruct kTheMethod = {
    .GetInstance = GetInstance,
};

const NullActuatorMethod nullActuator = &kTheMethod;
