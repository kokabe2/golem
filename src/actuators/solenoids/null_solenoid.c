// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "null_solenoid.h"

#include <stddef.h>

#include "bleu/v1/heap.h"

static Solenoid INSTANCE = NULL;

static void Delete(Solenoid* self) {}

static int NonsenseValue(Solenoid self) { return ~0; }

static const char* EmptyString(Solenoid self) { return ""; }

static bool True(Solenoid self) { return true; }

static void NoEffect(Solenoid self) {}

inline static Solenoid New(void) {
  Solenoid self = heap->New(sizeof(SolenoidInterfaceStruct));
  self->Delete = Delete;
  self->Id = NonsenseValue;
  self->Tag = EmptyString;
  self->State = EmptyString;
  self->IsUnlocked = True;
  self->Lock = NoEffect;
  self->Unlock = NoEffect;
  self->ForceUnlock = NoEffect;
  return self;
}

static Solenoid GetInstance(void) {
  if (INSTANCE == NULL) INSTANCE = New();
  return INSTANCE;
}

static const NullSolenoidMethodStruct kTheMethod = {
    .GetInstance = GetInstance,
};

const NullSolenoidMethod nullSolenoid = &kTheMethod;
