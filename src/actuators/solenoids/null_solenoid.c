// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "null_solenoid.h"

static int NonsenseValue(void) { return ~0; }

static const char* EmptyString(void) { return ""; }

static void NoEffect(void) {}

static bool False(void) { return false; }

static const SolenoidInterfaceStruct kTheMethod = {
    .Id = NonsenseValue,
    .Tag = EmptyString,
    .State = EmptyString,
    .Lock = NoEffect,
    .Unlock = NoEffect,
    .IsLocked = False,
};

const SolenoidInterface nullSolenoid = &kTheMethod;
