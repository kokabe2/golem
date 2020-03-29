// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "led.h"

#include "led_private.h"

static void Delete(Led* self) { (*self)->impl->Delete(self); }

static int Id(Led self) { return self->impl->Id(self); }

static const char* Tag(Led self) { return self->impl->Tag(self); }

static void TurnOff(Led self) { self->impl->TurnOff(self); }

static void TurnOn(Led self) { self->impl->TurnOn(self); }

static bool IsOff(Led self) { return self->impl->IsOff(self); }

static bool IsOn(Led self) { return self->impl->IsOn(self); }

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
