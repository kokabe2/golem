// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "null_solenoid.h"

static int Id(void) { return ~0; }

static const char* Tag(void) { return ""; }

static const char* State(void) { return ""; }

static void Lock(void) {}

static void Unlock(void) {}

static bool IsLocked(void) { return false; }

static const SolenoidInterfaceStruct kTheMethod = {
    .Id = Id, .Tag = Tag, .State = State, .Lock = Lock, .Unlock = Unlock, .IsLocked = IsLocked,
};

const SolenoidInterface nullSolenoid = &kTheMethod;
