// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "null_led_array.h"

#include <stddef.h>

#include "component_private.h"

static ComponentStruct the_singleton;
static Component the_instance = NULL;

static void Delete(Component* self) {}

static int NonsenseValue(Component self) { return ~0; }

static const char* EmptyString(Component self) { return ""; }

static void NoEffect(Component self) {}

static bool False(Component self) { return false; }

static void NoEffectWithInt(Component self, int led_id) {}

static bool FalseWithInt(Component self, int led_id) { return false; }

static const LedArrayInterfaceStruct kTheInterface = {
    .Delete = Delete,
    .Id = NonsenseValue,
    .Tag = EmptyString,
    .TurnAllOff = NoEffect,
    .TurnAllOn = NoEffect,
    .IsAllOff = False,
    .IsAllOn = False,
    .TurnOff = NoEffectWithInt,
    .TurnOn = NoEffectWithInt,
    .IsOff = FalseWithInt,
    .IsOn = FalseWithInt,
};

inline static Component New(void) {
  the_singleton.impl = (ComponentInterface)&kTheInterface;
  return &the_singleton;
}

static Component GetInstance(void) {
  if (the_instance == NULL) the_instance = New();
  return the_instance;
}

static const NullLedArrayMethodStruct kTheMethod = {
    .GetInstance = GetInstance,
};

const NullLedArrayMethod nullLedArray = &kTheMethod;
