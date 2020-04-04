// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "motor.h"

#include "component_private.h"

static void Delete(Component* self) { ((MotorInterface)((*self)->impl))->Delete(self); }

static int Id(Component self) { return ((MotorInterface)(self->impl))->Id(self); }

static const char* Tag(Component self) { return ((MotorInterface)(self->impl))->Tag(self); }

static const char* State(Component self) { return ((MotorInterface)(self->impl))->State(self); }

static bool IsOn(Component self) { return ((MotorInterface)(self->impl))->IsOn(self); }

static Command MotorOnCommand(Component self) { return ((MotorInterface)(self->impl))->MotorOnCommand(self); }

static Command MotorOffCommand(Component self) { return ((MotorInterface)(self->impl))->MotorOffCommand(self); }

static Command MotorForceOffCommand(Component self) {
  return ((MotorInterface)(self->impl))->MotorForceOffCommand(self);
}

static const char* GetDirection(Component self) { return ((MotorInterface)(self->impl))->GetDirection(self); }

static void SetDirection(Component self, const char* direction) {
  ((MotorInterface)(self->impl))->SetDirection(self, direction);
}

static int GetSpeed(Component self) { return ((MotorInterface)(self->impl))->GetSpeed(self); }

static void SetSpeed(Component self, int rpm) { ((MotorInterface)(self->impl))->SetSpeed(self, rpm); }

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
