// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "null_led.h"

#include <stddef.h>

#include "led_private.h"

static LedStruct the_singleton;
static Led the_instance = NULL;

static void Delete(Led* self) {}

static int NonsenseValue(Led self) { return ~0; }

static const char* EmptyString(Led self) { return ""; }

static void NoEffect(Led self) {}

static bool False(Led self) { return false; }

static const LedInterfaceStruct kTheInterface = {
    .Delete = Delete,
    .Id = NonsenseValue,
    .Tag = EmptyString,
    .TurnOff = NoEffect,
    .TurnOn = NoEffect,
    .IsOff = False,
    .IsOn = False,
};

inline static Led New(void) {
  the_singleton.impl = &kTheInterface;
  return &the_singleton;
}

static Led GetInstance(void) {
  if (the_instance == NULL) the_instance = New();
  return the_instance;
}

static const NullLedMethodStruct kTheMethod = {
    .GetInstance = GetInstance,
};

const NullLedMethod nullLed = &kTheMethod;
