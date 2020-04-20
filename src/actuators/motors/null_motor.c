// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "null_motor.h"

#include <stddef.h>

#include "bleu/v1/heap.h"

static Motor INSTANCE = NULL;

static void Delete(Motor* self) {}

static int NonsenseValue(Motor self) { return ~0; }

static const char* EmptyString(Motor self) { return ""; }

static bool True(Motor self) { return true; }

static void NoEffect(Motor self) {}

static void NoEffectWithString(Motor self, const char* direction) {}

static int Zero(Motor self) { return 0; }

static void NoEffectWithInt(Motor self, int rpm) {}

inline static Motor New(void) {
  Motor self = heap->New(sizeof(MotorInterfaceStruct));
  self->Delete = Delete;
  self->Id = NonsenseValue;
  self->Tag = EmptyString;
  self->State = EmptyString;
  self->IsStopped = True;
  self->Run = NoEffect;
  self->Stop = NoEffect;
  self->ForceStop = NoEffect;
  self->GetDirection = EmptyString;
  self->SetDirection = NoEffectWithString;
  self->GetSpeed = Zero;
  self->SetSpeed = NoEffectWithInt;
  return self;
}

static Motor GetInstance(void) {
  if (INSTANCE == NULL) INSTANCE = New();
  return INSTANCE;
}

static const NullMotorMethodStruct kTheMethod = {
    .GetInstance = GetInstance,
};

const NullMotorMethod nullMotor = &kTheMethod;
