// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "null_seven_segment_display.h"

static int NonsenseValue(void) { return ~0; }

static const char* EmptyString(void) { return ""; }

static void NoEffect(void) {}

static uint8_t Zero(void) { return 0; }

static void NoEffectWithUint8(uint8_t encoding) {}

static const SevenSegmentDisplayInterfaceStruct kTheMethod = {
    .Id = NonsenseValue,
    .Tag = EmptyString,
    .Clear = NoEffect,
    .Get = Zero,
    .Set = NoEffectWithUint8,
};

const SevenSegmentDisplayInterface nullSevenSegmentDisplay = &kTheMethod;
