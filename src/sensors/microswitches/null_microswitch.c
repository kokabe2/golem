// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "null_microswitch.h"

static int Id(void) { return ~0; }
static const char* Tag(void) { return ""; }
static const char* State(void) { return ""; }
static bool IsOff(void) { return false; }
static bool IsOn(void) { return false; }
static const MicroswitchInterfaceStruct kTheMethod = {
    .Id = Id, .Tag = Tag, .State = State, .IsOff = IsOff, .IsOn = IsOn,
};
const MicroswitchInterface nullMicroswitch = &kTheMethod;
