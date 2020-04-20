// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "null_pulse_motor.h"

#include <stddef.h>

#include "bleu/v1/heap.h"

static PulseMotor INSTANCE = NULL;

static void Delete(PulseMotor* self) {}

static int NonsenseValue(PulseMotor self) { return ~0; }

static const char* EmptyString(PulseMotor self) { return ""; }

static bool True(PulseMotor self) { return true; }

static void NoEffect(PulseMotor self) {}

static void NoEffectWithString(PulseMotor self, const char* direction) {}

static int Zero(PulseMotor self) { return 0; }

static void NoEffectWithInt(PulseMotor self, int rpm) {}

inline static PulseMotor New(void) {
  PulseMotor self = heap->New(sizeof(PulseMotorInterfaceStruct));
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
  self->GetMode = EmptyString;
  self->SelectMode = NoEffectWithString;
  self->GetPulseRate = Zero;
  self->SetPulseRate = NoEffectWithInt;
  self->GetPosition = Zero;
  return self;
}

static PulseMotor GetInstance(void) {
  if (INSTANCE == NULL) INSTANCE = New();
  return INSTANCE;
}

static const NullPulseMotorMethodStruct kTheMethod = {
    .GetInstance = GetInstance,
};

const NullPulseMotorMethod nullPulseMotor = &kTheMethod;
