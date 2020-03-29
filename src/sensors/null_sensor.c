// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "null_sensor.h"

#include <stddef.h>

#include "null_command.h"
#include "sensor_private.h"

static SensorStruct the_singleton;
static Sensor the_instance = NULL;

static void Delete(Sensor* self) {}

static int NonsenseValue(Sensor self) { return ~0; }

static const char* EmptyString(Sensor self) { return ""; }

static Command NullCommand(Sensor self, const char* expected_state, Command notification_command) {
  return nullCommand->GetInstance();
}

static bool False(Sensor self) { return false; }

static const SensorInterfaceStruct kTheInterface = {
    .Delete = Delete,
    .Id = NonsenseValue,
    .Tag = EmptyString,
    .SensorWatchCommand = NullCommand,
    .State = EmptyString,
    .IsDefaultState = False,
};

inline static Sensor New(void) {
  the_singleton.impl = &kTheInterface;
  return &the_singleton;
}

static Sensor GetInstance(void) {
  if (the_instance == NULL) the_instance = New();
  return the_instance;
}

static const NullSensorMethodStruct kTheMethod = {
    .GetInstance = GetInstance,
};

const NullSensorMethod nullSensor = &kTheMethod;
