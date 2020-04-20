// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "null_temperature_sensor.h"

#include <stddef.h>

#include "bleu/v1/heap.h"

static TemperatureSensor INSTANCE = NULL;

static void Delete(TemperatureSensor* self) {}

static int NonsenseValue(TemperatureSensor self) { return ~0; }

static const char* EmptyString(TemperatureSensor self) { return ""; }

static bool False(TemperatureSensor self) { return false; }

inline static TemperatureSensor New(void) {
  TemperatureSensor self = heap->New(sizeof(TemperatureSensorInterfaceStruct));
  self->Delete = Delete;
  self->Id = NonsenseValue;
  self->Tag = EmptyString;
  self->State = EmptyString;
  self->IsNormal = False;
  return self;
}

static TemperatureSensor GetInstance(void) {
  if (INSTANCE == NULL) INSTANCE = New();
  return INSTANCE;
}

static const NullTemperatureSensorMethodStruct kTheMethod = {
    .GetInstance = GetInstance,
};

const NullTemperatureSensorMethod nullTemperatureSensor = &kTheMethod;
