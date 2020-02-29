// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "null_motor.h"

#include "null_actuator.h"

static int NonsenseValue(void) { return ~0; }

static const char* EmptyString(void) { return ""; }

static void NoEffect(void) {}

static bool False(void) { return false; }

static int Zero(void) { return 0; }

static void NoEffectWithInt(int rmp) {}

static const MotorInterfaceStruct kTheMethod = {
    .Id = NonsenseValue,
    .Tag = EmptyString,
    .State = EmptyString,
    .Run = NoEffect,
    .Stop = NoEffect,
    .IsRunning = False,
    .ForceStop = NoEffect,
    .SetToCw = NoEffect,
    .SetToAcw = NoEffect,
    .IsCw = False,
    .GetSpeed = Zero,
    .SetSpeed = NoEffectWithInt,
};

const MotorInterface nullMotor = &kTheMethod;
