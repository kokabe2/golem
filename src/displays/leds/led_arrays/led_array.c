// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "led_array.h"

static void Delete(Component* self) { ((LedArrayInterface)(*self))->Delete(self); }

static int Id(Component self) { return ((LedArrayInterface)self)->Id(self); }

static const char* Tag(Component self) { return ((LedArrayInterface)self)->Tag(self); }

static void TurnAllOff(Component self) { ((LedArrayInterface)self)->TurnAllOff(self); }

static void TurnAllOn(Component self) { ((LedArrayInterface)self)->TurnAllOn(self); }

static bool IsAllOff(Component self) { return ((LedArrayInterface)self)->IsAllOff(self); }

static bool IsAllOn(Component self) { return ((LedArrayInterface)self)->IsAllOn(self); }

static void TurnOff(Component self, int led_id) { ((LedArrayInterface)self)->TurnOff(self, led_id); }

static void TurnOn(Component self, int led_id) { ((LedArrayInterface)self)->TurnOn(self, led_id); }

static bool IsOff(Component self, int led_id) { return ((LedArrayInterface)self)->IsOff(self, led_id); }

static bool IsOn(Component self, int led_id) { return ((LedArrayInterface)self)->IsOn(self, led_id); }

static const LedArrayInterfaceStruct kTheInterface = {
    .Delete = Delete,
    .Id = Id,
    .Tag = Tag,
    .TurnAllOff = TurnAllOff,
    .TurnAllOn = TurnAllOn,
    .IsAllOff = IsAllOff,
    .IsAllOn = IsAllOn,
    .TurnOff = TurnOff,
    .TurnOn = TurnOn,
    .IsOff = IsOff,
    .IsOn = IsOn,
};

const LedArrayInterface ledArray = &kTheInterface;
