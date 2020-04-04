// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "null_motor.h"

#include <stddef.h>

static Component the_instance = NULL;

static void Delete(Component* self) {}

static int NonsenseValue(Component self) { return ~0; }

static const char* EmptyString(Component self) { return ""; }

static bool False(Component self) { return false; }

static void NoEffectWithString(Component self, const char* direction) {}

static int Zero(Component self) { return 0; }

static void NoEffectWithInt(Component self, int rpm) {}

static const MotorInterfaceStruct kTheInterface = {
    .Delete = Delete,
    .Id = NonsenseValue,
    .Tag = EmptyString,
    .State = EmptyString,
    .IsOff = False,
    .GetDirection = EmptyString,
    .SetDirection = NoEffectWithString,
    .GetSpeed = Zero,
    .SetSpeed = NoEffectWithInt,
};

inline static Component New(void) { return (Component)&kTheInterface; }

static Component GetInstance(void) {
  if (the_instance == NULL) the_instance = New();
  return the_instance;
}

static const NullMotorMethodStruct kTheMethod = {
    .GetInstance = GetInstance,
};

const NullMotorMethod nullMotor = &kTheMethod;
