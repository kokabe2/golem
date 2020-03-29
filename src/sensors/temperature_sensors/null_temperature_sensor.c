// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "null_temperature_sensor.h"

#include <stddef.h>

#include "null_command.h"
#include "temperature_sensor_private.h"

static TemperatureSensorStruct the_singleton;
static TemperatureSensor the_instance = NULL;

static void Delete(TemperatureSensor* self) {}

static int NonsenseValue(TemperatureSensor self) { return ~0; }

static const char* EmptyString(TemperatureSensor self) { return ""; }

static Command NullCommand(TemperatureSensor self, const char* expected_state, Command notification_command) {
  return nullCommand->GetInstance();
}

static bool False(TemperatureSensor self) { return false; }

static const TemperatureSensorInterfaceStruct kTheInterface = {
    .Delete = Delete,
    .Id = NonsenseValue,
    .Tag = EmptyString,
    .SensorWatchCommand = NullCommand,
    .State = EmptyString,
    .IsNormal = False,
};

inline static TemperatureSensor New(void) {
  the_singleton.impl = &kTheInterface;
  return &the_singleton;
}

static TemperatureSensor GetInstance(void) {
  if (the_instance == NULL) the_instance = New();
  return the_instance;
}

static const NullTemperatureSensorMethodStruct kTheMethod = {
    .GetInstance = GetInstance,
};

const NullTemperatureSensorMethod nullTemperatureSensor = &kTheMethod;
