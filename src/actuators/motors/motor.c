// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "motor.h"

#include "motor_private.h"

static void Delete(Motor* self) { (*self)->impl->Delete(self); }

static int Id(Motor self) { return self->impl->Id(self); }

static const char* Tag(Motor self) { return self->impl->Tag(self); }

static const char* State(Motor self) { return self->impl->State(self); }

static bool IsOn(Motor self) { return self->impl->IsOn(self); }

static Command MotorOnCommand(Motor self) { return self->impl->MotorOnCommand(self); }

static Command MotorOffCommand(Motor self) { return self->impl->MotorOffCommand(self); }

static Command MotorForceOffCommand(Motor self) { return self->impl->MotorForceOffCommand(self); }

static const char* GetDirection(Motor self) { return self->impl->GetDirection(self); }

static void SetDirection(Motor self, const char* direction) { self->impl->SetDirection(self, direction); }

static int GetSpeed(Motor self) { return self->impl->GetSpeed(self); }

static void SetSpeed(Motor self, int rpm) { self->impl->SetSpeed(self, rpm); }

static const MotorInterfaceStruct kTheInterface = {
    .Delete = Delete,
    .Id = Id,
    .Tag = Tag,
    .State = State,
    .IsOn = IsOn,
    .MotorOnCommand = MotorOnCommand,
    .MotorOffCommand = MotorOffCommand,
    .MotorForceOffCommand = MotorForceOffCommand,
    .GetDirection = GetDirection,
    .SetDirection = SetDirection,
    .GetSpeed = GetSpeed,
    .SetSpeed = SetSpeed,
};

const MotorInterface motor = &kTheInterface;
