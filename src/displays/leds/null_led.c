// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "null_led.h"

#include <stddef.h>

#include "bleu/v1/heap.h"

static Led INSTANCE = NULL;

static void Delete(Led* self) {}

static int NonsenseValue(Led self) { return ~0; }

static const char* EmptyString(Led self) { return ""; }

static void NoEffect(Led self) {}

static bool False(Led self) { return false; }

inline static Led New(void) {
  Led self = heap->New(sizeof(LedInterfaceStruct));
  self->Delete = Delete;
  self->Id = NonsenseValue;
  self->Tag = EmptyString;
  self->TurnOff = NoEffect;
  self->TurnOn = NoEffect;
  self->IsOff = False;
  self->IsOn = False;
  return self;
}

static Led GetInstance(void) {
  if (INSTANCE == NULL) INSTANCE = New();
  return INSTANCE;
}

static const NullLedMethodStruct kTheMethod = {
    .GetInstance = GetInstance,
};

const NullLedMethod nullLed = &kTheMethod;
