// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "null_pulse_motor.h"

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
static void Excite(void) {}
static void Unexcite(void) {}
static bool IsExciting(void) { return false; }
static void Move(int pulse) {}
static int GetPulseRate(void) { return 0; }
static void SetPulseRate(int rate_in_pps) {}
static int GetPosition(void) { return 0; }
static const PulseMotorInterfaceStruct kTheMethod = {
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
    .Excite = Excite,
    .Unexcite = Unexcite,
    .IsExciting = IsExciting,
    .Move = Move,
    .GetPulseRate = GetPulseRate,
    .SetPulseRate = SetPulseRate,
    .GetPosition = GetPosition,
};
const PulseMotorInterface nullPulseMotor = &kTheMethod;
