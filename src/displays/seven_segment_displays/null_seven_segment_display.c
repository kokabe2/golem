// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "null_seven_segment_display.h"

#include <stddef.h>

#include "seven_segment_display_private.h"

static SevenSegmentDisplayStruct the_singleton;
static SevenSegmentDisplay the_instance = NULL;

static void Delete(SevenSegmentDisplay* self) {}

static int NonsenseValue(SevenSegmentDisplay self) { return ~0; }

static const char* EmptyString(SevenSegmentDisplay self) { return ""; }

static void NoEffect(SevenSegmentDisplay self) {}

static uint8_t Zero(SevenSegmentDisplay self) { return 0; }

static void NoEffectWithUint8(SevenSegmentDisplay self, uint8_t encoding) {}

static const SevenSegmentDisplayInterfaceStruct kTheInterface = {
    .Delete = Delete,
    .Id = NonsenseValue,
    .Tag = EmptyString,
    .Clear = NoEffect,
    .Get = Zero,
    .Set = NoEffectWithUint8,
};

inline static SevenSegmentDisplay New(void) {
  the_singleton.impl = &kTheInterface;
  return &the_singleton;
}

static SevenSegmentDisplay GetInstance(void) {
  if (the_instance == NULL) the_instance = New();
  return the_instance;
}

static const NullSevenSegmentDisplayMethodStruct kTheMethod = {
    .GetInstance = GetInstance,
};

const NullSevenSegmentDisplayMethod nullSevenSegmentDisplay = &kTheMethod;
