// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "null_sensor.h"

#include <stddef.h>

#include "bleu/v1/heap.h"

static Sensor INSTANCE = NULL;

static void Delete(Sensor* self) {}

static int NonsenseValue(Sensor self) { return ~0; }

static const char* EmptyString(Sensor self) { return ""; }

static bool False(Sensor self) { return false; }

inline static Sensor New(void) {
  Sensor self = heap->New(sizeof(SensorInterfaceStruct));
  self->Delete = Delete;
  self->Id = NonsenseValue;
  self->Tag = EmptyString;
  self->State = EmptyString;
  self->IsDefaultState = False;
  return self;
}

static Sensor GetInstance(void) {
  if (INSTANCE == NULL) INSTANCE = New();
  return INSTANCE;
}

static const NullSensorMethodStruct kTheMethod = {
    .GetInstance = GetInstance,
};

const NullSensorMethod nullSensor = &kTheMethod;
