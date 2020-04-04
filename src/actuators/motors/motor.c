// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "motor.h"

static void Delete(Component* self) { ((MotorInterface)(*self))->Delete(self); }

static int Id(Component self) { return ((MotorInterface)self)->Id(self); }

static const char* Tag(Component self) { return ((MotorInterface)self)->Tag(self); }

static const char* State(Component self) { return ((MotorInterface)self)->State(self); }

static bool IsOff(Component self) { return ((MotorInterface)self)->IsOff(self); }

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
    .IsOff = IsOff,
    .GetDirection = GetDirection,
    .SetDirection = SetDirection,
    .GetSpeed = GetSpeed,
    .SetSpeed = SetSpeed,
};

const MotorInterface motor = &kTheInterface;
