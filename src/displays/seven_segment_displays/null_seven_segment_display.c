// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "null_seven_segment_display.h"

#include <stddef.h>

static Component the_instance = NULL;

static void Delete(Component* self) {}

static int NonsenseValue(Component self) { return ~0; }

static const char* EmptyString(Component self) { return ""; }

static void NoEffect(Component self) {}

static uint8_t Zero(Component self) { return 0; }

static void NoEffectWithUint8(Component self, uint8_t encoding) {}

static const SevenSegmentDisplayInterfaceStruct kTheInterface = {
    .Delete = Delete,
    .Id = NonsenseValue,
    .Tag = EmptyString,
    .Clear = NoEffect,
    .Get = Zero,
    .Set = NoEffectWithUint8,
};

inline static Component New(void) { return (Component)&kTheInterface; }

static Component GetInstance(void) {
  if (the_instance == NULL) the_instance = New();
  return the_instance;
}

static const NullSevenSegmentDisplayMethodStruct kTheMethod = {
    .GetInstance = GetInstance,
};

const NullSevenSegmentDisplayMethod nullSevenSegmentDisplay = &kTheMethod;
