// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "pulse_motor.h"

#include "component_private.h"

static void Delete(Component* self) { ((PulseMotorInterface)((*self)->impl))->Delete(self); }

static int Id(Component self) { return ((PulseMotorInterface)(self->impl))->Id(self); }

static const char* Tag(Component self) { return ((PulseMotorInterface)(self->impl))->Tag(self); }

static const char* State(Component self) { return ((PulseMotorInterface)(self->impl))->State(self); }

static bool IsOn(Component self) { return ((PulseMotorInterface)(self->impl))->IsOn(self); }

static Command PulseMotorOnCommand(Component self) {
  return ((PulseMotorInterface)(self->impl))->PulseMotorOnCommand(self);
}

static Command PulseMotorOffCommand(Component self) {
  return ((PulseMotorInterface)(self->impl))->PulseMotorOffCommand(self);
}

static Command PulseMotorForceOffCommand(Component self) {
  return ((PulseMotorInterface)(self->impl))->PulseMotorForceOffCommand(self);
}

static const char* GetDirection(Component self) { return ((PulseMotorInterface)(self->impl))->GetDirection(self); }

static void SetDirection(Component self, const char* direction) {
  ((PulseMotorInterface)(self->impl))->SetDirection(self, direction);
}

static int GetSpeed(Component self) { return ((PulseMotorInterface)(self->impl))->GetSpeed(self); }

static void SetSpeed(Component self, int rpm) { ((PulseMotorInterface)(self->impl))->SetSpeed(self, rpm); }

static Command PulseMotorStopCommand(Component self, int pulse) {
  return ((PulseMotorInterface)(self->impl))->PulseMotorStopCommand(self, pulse);
}

static Command PulseMotorWatchCommand(Component self, int pulse, Command notification_command) {
  return ((PulseMotorInterface)(self->impl))->PulseMotorWatchCommand(self, pulse, notification_command);
}

static const char* GetMode(Component self) { return ((PulseMotorInterface)(self->impl))->GetMode(self); }

static void SelectMode(Component self, const char* mode) {
  ((PulseMotorInterface)(self->impl))->SelectMode(self, mode);
}

static int GetPulseRate(Component self) { return ((PulseMotorInterface)(self->impl))->GetPulseRate(self); }

static void SetPulseRate(Component self, int pps) { ((PulseMotorInterface)(self->impl))->SetPulseRate(self, pps); }

static int GetPosition(Component self) { return ((PulseMotorInterface)(self->impl))->GetPosition(self); }

static const PulseMotorInterfaceStruct kTheInterface = {
    .Delete = Delete,
    .Id = Id,
    .Tag = Tag,
    .State = State,
    .IsOn = IsOn,
    .PulseMotorOnCommand = PulseMotorOnCommand,
    .PulseMotorOffCommand = PulseMotorOffCommand,
    .PulseMotorForceOffCommand = PulseMotorForceOffCommand,
    .GetDirection = GetDirection,
    .SetDirection = SetDirection,
    .GetSpeed = GetSpeed,
    .SetSpeed = SetSpeed,
    .PulseMotorStopCommand = PulseMotorStopCommand,
    .PulseMotorWatchCommand = PulseMotorWatchCommand,
    .GetMode = GetMode,
    .SelectMode = SelectMode,
    .GetPulseRate = GetPulseRate,
    .SetPulseRate = SetPulseRate,
    .GetPosition = GetPosition,
};

const PulseMotorInterface pulseMotor = &kTheInterface;
