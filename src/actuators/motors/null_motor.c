// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "null_motor.h"

#include <stddef.h>

#include "motor_private.h"
#include "null_command.h"

static MotorStruct the_singleton;
static Motor the_instance = NULL;

static void Delete(Motor* self) {}

static int NonsenseValue(Motor self) { return ~0; }

static const char* EmptyString(Motor self) { return ""; }

static bool False(Motor self) { return false; }

static Command NullCommand(Motor self) { return nullCommand->GetInstance(); }

static void NoEffectWithString(Motor self, const char* direction) {}

static int Zero(Motor self) { return 0; }

static void NoEffectWithInt(Motor self, int rpm) {}

static const MotorInterfaceStruct kTheInterface = {
    .Delete = Delete,
    .Id = NonsenseValue,
    .Tag = EmptyString,
    .State = EmptyString,
    .IsOn = False,
    .MotorOnCommand = NullCommand,
    .MotorOffCommand = NullCommand,
    .MotorForceOffCommand = NullCommand,
    .GetDirection = EmptyString,
    .SetDirection = NoEffectWithString,
    .GetSpeed = Zero,
    .SetSpeed = NoEffectWithInt,
};

inline static Motor New(void) {
  the_singleton.impl = &kTheInterface;
  return &the_singleton;
}

static Motor GetInstance(void) {
  if (the_instance == NULL) the_instance = New();
  return the_instance;
}

static const NullMotorMethodStruct kTheMethod = {
    .GetInstance = GetInstance,
};

const NullMotorMethod nullMotor = &kTheMethod;
