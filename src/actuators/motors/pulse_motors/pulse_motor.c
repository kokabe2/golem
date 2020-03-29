// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "pulse_motor.h"

#include "pulse_motor_private.h"

static void Delete(PulseMotor* self) { (*self)->impl->Delete(self); }

static int Id(PulseMotor self) { return self->impl->Id(self); }

static const char* Tag(PulseMotor self) { return self->impl->Tag(self); }

static const char* State(PulseMotor self) { return self->impl->State(self); }

static bool IsOn(PulseMotor self) { return self->impl->IsOn(self); }

static Command PulseMotorOnCommand(PulseMotor self) { return self->impl->PulseMotorOnCommand(self); }

static Command PulseMotorOffCommand(PulseMotor self) { return self->impl->PulseMotorOffCommand(self); }

static Command PulseMotorForceOffCommand(PulseMotor self) { return self->impl->PulseMotorForceOffCommand(self); }

static const char* GetDirection(PulseMotor self) { return self->impl->GetDirection(self); }

static void SetDirection(PulseMotor self, const char* direction) { self->impl->SetDirection(self, direction); }

static int GetSpeed(PulseMotor self) { return self->impl->GetSpeed(self); }

static void SetSpeed(PulseMotor self, int rpm) { self->impl->SetSpeed(self, rpm); }

static Command PulseMotorStopCommand(PulseMotor self, int pulse) {
  return self->impl->PulseMotorStopCommand(self, pulse);
}

static Command PulseMotorWatchCommand(PulseMotor self, int pulse, Command notification_command) {
  return self->impl->PulseMotorWatchCommand(self, pulse, notification_command);
}

static const char* GetMode(PulseMotor self) { return self->impl->GetMode(self); }

static void SelectMode(PulseMotor self, const char* mode) { self->impl->SelectMode(self, mode); }

static int GetPulseRate(PulseMotor self) { return self->impl->GetPulseRate(self); }

static void SetPulseRate(PulseMotor self, int pps) { self->impl->SetPulseRate(self, pps); }

static int GetPosition(PulseMotor self) { return self->impl->GetPosition(self); }

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
