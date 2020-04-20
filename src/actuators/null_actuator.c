// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "null_actuator.h"

#include <stddef.h>

#include "bleu/v1/heap.h"

static Actuator INSTANCE = NULL;

static void Delete(Actuator* self) {}

static int NonsenseValue(Actuator self) { return ~0; }

static const char* EmptyString(Actuator self) { return ""; }

static bool True(Actuator self) { return true; }

static void NoEffect(Actuator self) {}

inline static Actuator New(void) {
  Actuator self = heap->New(sizeof(ActuatorInterfaceStruct));
  self->Delete = Delete;
  self->Id = NonsenseValue;
  self->Tag = EmptyString;
  self->State = EmptyString;
  self->IsOff = True;
  self->TurnOn = NoEffect;
  self->TurnOff = NoEffect;
  self->ForceTurnOff = NoEffect;
  return self;
}

static Actuator GetInstance(void) {
  if (INSTANCE == NULL) INSTANCE = New();
  return INSTANCE;
}

static const NullActuatorMethodStruct kTheMethod = {
    .GetInstance = GetInstance,
};

const NullActuatorMethod nullActuator = &kTheMethod;
