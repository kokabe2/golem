// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "null_temperature_sensor.h"

#include <stddef.h>

static Component the_instance = NULL;

static void Delete(Component* self) {}

static int NonsenseValue(Component self) { return ~0; }

static const char* EmptyString(Component self) { return ""; }

static bool False(Component self) { return false; }

static const TemperatureSensorInterfaceStruct kTheInterface = {
    .Delete = Delete,
    .Id = NonsenseValue,
    .Tag = EmptyString,
    .State = EmptyString,
    .IsNormal = False,
};

inline static Component New(void) { return (Component)&kTheInterface; }

static Component GetInstance(void) {
  if (the_instance == NULL) the_instance = New();
  return the_instance;
}

static const NullTemperatureSensorMethodStruct kTheMethod = {
    .GetInstance = GetInstance,
};

const NullTemperatureSensorMethod nullTemperatureSensor = &kTheMethod;
