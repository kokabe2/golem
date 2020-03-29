// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "null_led_array.h"

#include <stddef.h>

#include "led_array_private.h"

static LedArrayStruct the_singleton;
static LedArray the_instance = NULL;

static void Delete(LedArray* self) {}

static int NonsenseValue(LedArray self) { return ~0; }

static const char* EmptyString(LedArray self) { return ""; }

static void NoEffect(LedArray self) {}

static bool False(LedArray self) { return false; }

static void NoEffectWithInt(LedArray self, int led_id) {}

static bool FalseWithInt(LedArray self, int led_id) { return false; }

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

inline static LedArray New(void) {
  the_singleton.impl = &kTheInterface;
  return &the_singleton;
}

static LedArray GetInstance(void) {
  if (the_instance == NULL) the_instance = New();
  return the_instance;
}

static const NullLedArrayMethodStruct kTheMethod = {
    .GetInstance = GetInstance,
};

const NullLedArrayMethod nullLedArray = &kTheMethod;
