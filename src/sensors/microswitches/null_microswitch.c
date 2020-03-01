// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "null_microswitch.h"

static int NonsenseValue(void) { return ~0; }

static const char* EmptyString(void) { return ""; }

static bool False(void) { return false; }

static const MicroswitchInterfaceStruct kTheMethod = {
    .Id = NonsenseValue, .Tag = EmptyString, .State = EmptyString, .IsOff = False, .IsOn = False,
};

const MicroswitchInterface nullMicroswitch = &kTheMethod;
