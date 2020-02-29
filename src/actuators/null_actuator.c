// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "null_actuator.h"

static int NonsenseValue(void) { return ~0; }

static const char* EmptyString(void) { return ""; }

static void NoEffect(void) {}

static bool False(void) { return false; }

static const ActuatorInterfaceStruct kTheMethod = {
    .Id = NonsenseValue,
    .Tag = EmptyString,
    .State = EmptyString,
    .Activate = NoEffect,
    .Deactivate = NoEffect,
    .IsActive = False,
};

const ActuatorInterface nullActuator = &kTheMethod;
