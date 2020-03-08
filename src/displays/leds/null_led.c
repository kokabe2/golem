// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "null_led.h"

static int NonsenseValue(void) { return ~0; }

static const char* EmptyString(void) { return ""; }

static void NoEffect(void) {}

static bool False(void) { return false; }

static const LedInterfaceStruct kTheMethod = {
    .Id = NonsenseValue,
    .Tag = EmptyString,
    .TurnOff = NoEffect,
    .TurnOn = NoEffect,
    .IsOff = False,
    .IsOn = False,
};

const LedInterface nullLed = &kTheMethod;
