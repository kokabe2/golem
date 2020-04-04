// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "microswitch.h"

static void Delete(Component* self) { ((MicroswitchInterface)(*self))->Delete(self); }

static int Id(Component self) { return ((MicroswitchInterface)self)->Id(self); }

static const char* Tag(Component self) { return ((MicroswitchInterface)self)->Tag(self); }

static const char* State(Component self) { return ((MicroswitchInterface)self)->State(self); }

static bool IsOff(Component self) { return ((MicroswitchInterface)self)->IsOff(self); }

static bool IsOn(Component self) { return ((MicroswitchInterface)self)->IsOn(self); }

static const MicroswitchInterfaceStruct kTheInterface = {
    .Delete = Delete,
    .Id = Id,
    .Tag = Tag,
    .State = State,
    .IsOff = IsOff,
    .IsOn = IsOn,
};

const MicroswitchInterface microswitch = &kTheInterface;
