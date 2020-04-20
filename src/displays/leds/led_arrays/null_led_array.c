// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "null_led_array.h"

#include <stddef.h>

#include "bleu/v1/heap.h"

static LedArray INSTANCE = NULL;

static void Delete(LedArray* self) {}

static int NonsenseValue(LedArray self) { return ~0; }

static const char* EmptyString(LedArray self) { return ""; }

static void NoEffect(LedArray self) {}

static bool False(LedArray self) { return false; }

static void NoEffectWithInt(LedArray self, int led_id) {}

static bool FalseWithInt(LedArray self, int led_id) { return false; }

inline static LedArray New(void) {
  LedArray self = heap->New(sizeof(LedArrayInterfaceStruct));
  self->Delete = Delete;
  self->Id = NonsenseValue;
  self->Tag = EmptyString;
  self->TurnAllOff = NoEffect;
  self->TurnAllOn = NoEffect;
  self->IsAllOff = False;
  self->IsAllOn = False;
  self->TurnOff = NoEffectWithInt;
  self->TurnOn = NoEffectWithInt;
  self->IsOff = FalseWithInt;
  self->IsOn = FalseWithInt;
  return self;
}

static LedArray GetInstance(void) {
  if (INSTANCE == NULL) INSTANCE = New();
  return INSTANCE;
}

static const NullLedArrayMethodStruct kTheMethod = {
    .GetInstance = GetInstance,
};

const NullLedArrayMethod nullLedArray = &kTheMethod;
