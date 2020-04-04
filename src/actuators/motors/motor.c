// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "motor.h"

static void Delete(Component* self) { ((MotorInterface)(*self))->Delete(self); }

static int Id(Component self) { return ((MotorInterface)self)->Id(self); }

static const char* Tag(Component self) { return ((MotorInterface)self)->Tag(self); }

static const char* State(Component self) { return ((MotorInterface)self)->State(self); }

static bool IsOn(Component self) { return ((MotorInterface)self)->IsOn(self); }

static Command MotorOnCommand(Component self) { return ((MotorInterface)self)->MotorOnCommand(self); }

static Command MotorOffCommand(Component self) { return ((MotorInterface)self)->MotorOffCommand(self); }

static Command MotorForceOffCommand(Component self) { return ((MotorInterface)self)->MotorForceOffCommand(self); }

static const char* GetDirection(Component self) { return ((MotorInterface)self)->GetDirection(self); }

static void SetDirection(Component self, const char* direction) {
  ((MotorInterface)self)->SetDirection(self, direction);
}

static int GetSpeed(Component self) { return ((MotorInterface)self)->GetSpeed(self); }

static void SetSpeed(Component self, int rpm) { ((MotorInterface)self)->SetSpeed(self, rpm); }

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
