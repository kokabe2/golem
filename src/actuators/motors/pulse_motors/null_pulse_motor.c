// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "null_pulse_motor.h"

static int NonsenseValue(void) { return ~0; }

static const char* EmptyString(void) { return ""; }

static void NoEffect(void) {}

static bool False(void) { return false; }

static int Zero(void) { return 0; }

static void NoEffectWithInt(int unused) {}

static const PulseMotorInterfaceStruct kTheMethod = {
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
    .Excite = NoEffect,
    .Unexcite = NoEffect,
    .IsExciting = False,
    .Move = NoEffectWithInt,
    .StopAfter = NoEffectWithInt,
    .GetPulseRate = Zero,
    .SetPulseRate = NoEffectWithInt,
    .GetPosition = Zero,
};

const PulseMotorInterface nullPulseMotor = &kTheMethod;
