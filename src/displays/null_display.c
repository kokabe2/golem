// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "null_display.h"

#include <stddef.h>

#include "bleu/v1/heap.h"

static Display INSTANCE = NULL;

static void Delete(Display* self) {}

static int NonsenseValue(Display self) { return ~0; }

static const char* EmptyString(Display self) { return ""; }

static void NoEffect(Display self) {}

static const DisplayInterfaceStruct kTheInterface = {
    .Delete = Delete,
    .Id = NonsenseValue,
    .Tag = EmptyString,
    .Reset = NoEffect,
};

inline static Display New(void) {
  Display self = heap->New(sizeof(DisplayInterfaceStruct));
  self->Delete = Delete;
  self->Id = NonsenseValue;
  self->Tag = EmptyString;
  self->Reset = NoEffect;
  return self;
}

static Display GetInstance(void) {
  if (INSTANCE == NULL) INSTANCE = New();
  return INSTANCE;
}

static const NullDisplayMethodStruct kTheMethod = {
    .GetInstance = GetInstance,
};

const NullDisplayMethod nullDisplay = &kTheMethod;
