// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "led_array.h"

#include "component_private.h"

static void Delete(Component* self) { ((LedArrayInterface)((*self)->impl))->Delete(self); }

static int Id(Component self) { return ((LedArrayInterface)(self->impl))->Id(self); }

static const char* Tag(Component self) { return ((LedArrayInterface)(self->impl))->Tag(self); }

static void TurnAllOff(Component self) { ((LedArrayInterface)(self->impl))->TurnAllOff(self); }

static void TurnAllOn(Component self) { ((LedArrayInterface)(self->impl))->TurnAllOn(self); }

static bool IsAllOff(Component self) { return ((LedArrayInterface)(self->impl))->IsAllOff(self); }

static bool IsAllOn(Component self) { return ((LedArrayInterface)(self->impl))->IsAllOn(self); }

static void TurnOff(Component self, int led_id) { ((LedArrayInterface)(self->impl))->TurnOff(self, led_id); }

static void TurnOn(Component self, int led_id) { ((LedArrayInterface)(self->impl))->TurnOn(self, led_id); }

static bool IsOff(Component self, int led_id) { return ((LedArrayInterface)(self->impl))->IsOff(self, led_id); }

static bool IsOn(Component self, int led_id) { return ((LedArrayInterface)(self->impl))->IsOn(self, led_id); }

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
