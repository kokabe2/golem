// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "led.h"

static void Delete(Component* self) { ((LedInterface)(*self))->Delete(self); }

static int Id(Component self) { return ((LedInterface)self)->Id(self); }

static const char* Tag(Component self) { return ((LedInterface)self)->Tag(self); }

static void TurnOff(Component self) { ((LedInterface)self)->TurnOff(self); }

static void TurnOn(Component self) { ((LedInterface)self)->TurnOn(self); }

static bool IsOff(Component self) { return ((LedInterface)self)->IsOff(self); }

static bool IsOn(Component self) { return ((LedInterface)self)->IsOn(self); }

static const LedInterfaceStruct kTheInterface = {
    .Delete = Delete,
    .Id = Id,
    .Tag = Tag,
    .TurnOff = TurnOff,
    .TurnOn = TurnOn,
    .IsOff = IsOff,
    .IsOn = IsOn,
};

const LedInterface led = &kTheInterface;
