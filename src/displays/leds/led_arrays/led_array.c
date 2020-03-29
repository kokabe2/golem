// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "led_array.h"

#include "led_array_private.h"

static void Delete(LedArray* self) { (*self)->impl->Delete(self); }

static int Id(LedArray self) { return self->impl->Id(self); }

static const char* Tag(LedArray self) { return self->impl->Tag(self); }

static void TurnAllOff(LedArray self) { self->impl->TurnAllOff(self); }

static void TurnAllOn(LedArray self) { self->impl->TurnAllOn(self); }

static bool IsAllOff(LedArray self) { return self->impl->IsAllOff(self); }

static bool IsAllOn(LedArray self) { return self->impl->IsAllOn(self); }

static void TurnOff(LedArray self, int led_id) { self->impl->TurnOff(self, led_id); }

static void TurnOn(LedArray self, int led_id) { self->impl->TurnOn(self, led_id); }

static bool IsOff(LedArray self, int led_id) { return self->impl->IsOff(self, led_id); }

static bool IsOn(LedArray self, int led_id) { return self->impl->IsOn(self, led_id); }

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
