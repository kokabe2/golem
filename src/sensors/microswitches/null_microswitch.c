// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "null_microswitch.h"

#include <stddef.h>

#include "bleu/v1/heap.h"

static Microswitch INSTANCE = NULL;

static void Delete(Microswitch* self) {}

static int NonsenseValue(Microswitch self) { return ~0; }

static const char* EmptyString(Microswitch self) { return ""; }

static bool False(Microswitch self) { return false; }

inline static Microswitch New(void) {
  Microswitch self = heap->New(sizeof(MicroswitchInterfaceStruct));
  self->Delete = Delete;
  self->Id = NonsenseValue;
  self->Tag = EmptyString;
  self->State = EmptyString;
  self->IsOff = False;
  self->IsOn = False;
  return self;
}

static Microswitch GetInstance(void) {
  if (INSTANCE == NULL) INSTANCE = New();
  return INSTANCE;
}

static const NullMicroswitchMethodStruct kTheMethod = {
    .GetInstance = GetInstance,
};

const NullMicroswitchMethod nullMicroswitch = &kTheMethod;
