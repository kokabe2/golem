// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "null_led_array.h"

static int NonsenseValue(void) { return ~0; }

static const char* EmptyString(void) { return ""; }

static void NoEffect(void) {}

static bool False(void) { return false; }

static void NoEffectWithInt(int led_id) {}

static bool FalseWithInt(int led_id) { return false; }

static const LedArrayInterfaceStruct kTheMethod = {
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

const LedArrayInterface nullLedArray = &kTheMethod;
