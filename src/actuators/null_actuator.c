// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "null_actuator.h"

static int Id(void) { return ~0; }
static const char* Tag(void) { return ""; }
static const char* State(void) { return ""; }
static void Activate(void) {}
static void Deactivate(void) {}
static bool IsActive(void) { return false; }
static const ActuatorInterfaceStruct kTheMethod = {
    .Id = Id,
    .Tag = Tag,
    .State = State,
    .Activate = Activate,
    .Deactivate = Deactivate,
    .IsActive = IsActive,
};
const ActuatorInterface nullActuator = &kTheMethod;
