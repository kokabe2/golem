// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "null_seven_segment_display.h"

#include <stddef.h>

#include "bleu/v1/heap.h"

static SevenSegmentDisplay INSTANCE = NULL;

static void Delete(SevenSegmentDisplay* self) {}

static int NonsenseValue(SevenSegmentDisplay self) { return ~0; }

static const char* EmptyString(SevenSegmentDisplay self) { return ""; }

static void NoEffect(SevenSegmentDisplay self) {}

static uint8_t Zero(SevenSegmentDisplay self) { return 0; }

static void NoEffectWithUint8(SevenSegmentDisplay self, uint8_t encoding) {}

inline static SevenSegmentDisplay New(void) {
  SevenSegmentDisplay self = heap->New(sizeof(SevenSegmentDisplayInterfaceStruct));
  self->Delete = Delete;
  self->Id = NonsenseValue;
  self->Tag = EmptyString;
  self->Clear = NoEffect;
  self->Get = Zero;
  self->Set = NoEffectWithUint8;
  return self;
}

static SevenSegmentDisplay GetInstance(void) {
  if (INSTANCE == NULL) INSTANCE = New();
  return INSTANCE;
}

static const NullSevenSegmentDisplayMethodStruct kTheMethod = {
    .GetInstance = GetInstance,
};

const NullSevenSegmentDisplayMethod nullSevenSegmentDisplay = &kTheMethod;
