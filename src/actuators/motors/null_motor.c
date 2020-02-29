// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "null_motor.h"

static int Id(void) { return ~0; }

static const char* Tag(void) { return ""; }

static const char* State(void) { return ""; }

static void Run(void) {}

static void Stop(void) {}

static bool IsRunning(void) { return false; }

static void ForceStop(void) {}

static void SetToCw(void) {}

static void SetToAcw(void) {}

static bool IsCw(void) { return false; }

static int GetSpeed(void) { return 0; }

static void SetSpeed(int speed_in_rpm) {}

static const MotorInterfaceStruct kTheMethod = {
    .Id = Id,
    .Tag = Tag,
    .State = State,
    .Run = Run,
    .Stop = Stop,
    .IsRunning = IsRunning,
    .ForceStop = ForceStop,
    .SetToCw = SetToCw,
    .SetToAcw = SetToAcw,
    .IsCw = IsCw,
    .GetSpeed = GetSpeed,
    .SetSpeed = SetSpeed,
};

const MotorInterface nullMotor = &kTheMethod;
