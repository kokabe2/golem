// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "temperature_sensor.h"

#include "temperature_sensor_private.h"

static void Delete(TemperatureSensor* self) { (*self)->impl->Delete(self); }

static int Id(TemperatureSensor self) { return self->impl->Id(self); }

static const char* Tag(TemperatureSensor self) { return self->impl->Tag(self); }

static Command SensorWatchCommand(TemperatureSensor self, const char* expected_state, Command notification_command) {
  return self->impl->SensorWatchCommand(self, expected_state, notification_command);
}

static const char* State(TemperatureSensor self) { return self->impl->State(self); }

static bool IsNormal(TemperatureSensor self) { return self->impl->IsNormal(self); }

static const TemperatureSensorInterfaceStruct kTheInterface = {
    .Delete = Delete,
    .Id = Id,
    .Tag = Tag,
    .SensorWatchCommand = SensorWatchCommand,
    .State = State,
    .IsNormal = IsNormal,
};

const TemperatureSensorInterface temperatureSensor = &kTheInterface;
