// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "null_pulse_motor.h"

#include <stddef.h>

static Component the_instance = NULL;

static void Delete(Component* self) {}

static int NonsenseValue(Component self) { return ~0; }

static const char* EmptyString(Component self) { return ""; }

static bool True(Component self) { return true; }

static void NoEffect(Component self) {}

static void NoEffectWithString(Component self, const char* direction) {}

static int Zero(Component self) { return 0; }

static void NoEffectWithInt(Component self, int rpm) {}

static const PulseMotorInterfaceStruct kTheInterface = {
    .Delete = Delete,
    .Id = NonsenseValue,
    .Tag = EmptyString,
    .State = EmptyString,
    .IsStopped = True,
    .Run = NoEffect,
    .Stop = NoEffect,
    .ForceStop = NoEffect,
    .GetDirection = EmptyString,
    .SetDirection = NoEffectWithString,
    .GetSpeed = Zero,
    .SetSpeed = NoEffectWithInt,
    .GetMode = EmptyString,
    .SelectMode = NoEffectWithString,
    .GetPulseRate = Zero,
    .SetPulseRate = NoEffectWithInt,
    .GetPosition = Zero,
};

inline static Component New(void) { return (Component)&kTheInterface; }

static Component GetInstance(void) {
  if (the_instance == NULL) the_instance = New();
  return the_instance;
}

static const NullPulseMotorMethodStruct kTheMethod = {
    .GetInstance = GetInstance,
};

const NullPulseMotorMethod nullPulseMotor = &kTheMethod;
