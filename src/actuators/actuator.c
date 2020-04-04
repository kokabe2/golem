// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "actuator.h"

static void Delete(Component* self) { ((ActuatorInterface)(*self))->Delete(self); }

static int Id(Component self) { return ((ActuatorInterface)self)->Id(self); }

static const char* Tag(Component self) { return ((ActuatorInterface)self)->Tag(self); }

static const char* State(Component self) { return ((ActuatorInterface)self)->State(self); }

static bool IsOff(Component self) { return ((ActuatorInterface)self)->IsOff(self); }

static const ActuatorInterfaceStruct kTheInterface = {
    .Delete = Delete,
    .Id = Id,
    .Tag = Tag,
    .State = State,
    .IsOff = IsOff,
};

const ActuatorInterface actuator = &kTheInterface;
