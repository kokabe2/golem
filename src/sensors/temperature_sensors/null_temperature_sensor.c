// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "null_temperature_sensor.h"

#include <stddef.h>

#include "null_command.h"

static Component the_instance = NULL;

static void Delete(Component* self) {}

static int NonsenseValue(Component self) { return ~0; }

static const char* EmptyString(Component self) { return ""; }

static Command NullCommand(Component self, const char* expected_state, Command notification_command) {
  return nullCommand->GetInstance();
}

static bool False(Component self) { return false; }

static const TemperatureSensorInterfaceStruct kTheInterface = {
    .Delete = Delete,
    .Id = NonsenseValue,
    .Tag = EmptyString,
    .TemperatureSensorWatchCommand = NullCommand,
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
