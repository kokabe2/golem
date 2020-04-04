// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "pulse_motor.h"

static void Delete(Component* self) { ((PulseMotorInterface)(*self))->Delete(self); }

static int Id(Component self) { return ((PulseMotorInterface)self)->Id(self); }

static const char* Tag(Component self) { return ((PulseMotorInterface)self)->Tag(self); }

static const char* State(Component self) { return ((PulseMotorInterface)self)->State(self); }

static bool IsOff(Component self) { return ((PulseMotorInterface)self)->IsOff(self); }

static const char* GetDirection(Component self) { return ((PulseMotorInterface)self)->GetDirection(self); }

static void SetDirection(Component self, const char* direction) {
  ((PulseMotorInterface)self)->SetDirection(self, direction);
}

static int GetSpeed(Component self) { return ((PulseMotorInterface)self)->GetSpeed(self); }

static void SetSpeed(Component self, int rpm) { ((PulseMotorInterface)self)->SetSpeed(self, rpm); }

static const char* GetMode(Component self) { return ((PulseMotorInterface)self)->GetMode(self); }

static void SelectMode(Component self, const char* mode) { ((PulseMotorInterface)self)->SelectMode(self, mode); }

static int GetPulseRate(Component self) { return ((PulseMotorInterface)self)->GetPulseRate(self); }

static void SetPulseRate(Component self, int pps) { ((PulseMotorInterface)self)->SetPulseRate(self, pps); }

static int GetPosition(Component self) { return ((PulseMotorInterface)self)->GetPosition(self); }

static const PulseMotorInterfaceStruct kTheInterface = {
    .Delete = Delete,
    .Id = Id,
    .Tag = Tag,
    .State = State,
    .IsOff = IsOff,
    .GetDirection = GetDirection,
    .SetDirection = SetDirection,
    .GetSpeed = GetSpeed,
    .SetSpeed = SetSpeed,
    .GetMode = GetMode,
    .SelectMode = SelectMode,
    .GetPulseRate = GetPulseRate,
    .SetPulseRate = SetPulseRate,
    .GetPosition = GetPosition,
};

const PulseMotorInterface pulseMotor = &kTheInterface;
