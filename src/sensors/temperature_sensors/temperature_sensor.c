// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "temperature_sensor.h"

#include "component_private.h"

static void Delete(Component* self) { ((TemperatureSensorInterface)((*self)->impl))->Delete(self); }

static int Id(Component self) { return ((TemperatureSensorInterface)(self->impl))->Id(self); }

static const char* Tag(Component self) { return ((TemperatureSensorInterface)(self->impl))->Tag(self); }

static Command TemperatureSensorWatchCommand(Component self, const char* expected_state, Command notification_command) {
  return ((TemperatureSensorInterface)(self->impl))
      ->TemperatureSensorWatchCommand(self, expected_state, notification_command);
}

static const char* State(Component self) { return ((TemperatureSensorInterface)(self->impl))->State(self); }

static bool IsNormal(Component self) { return ((TemperatureSensorInterface)(self->impl))->IsNormal(self); }

static const TemperatureSensorInterfaceStruct kTheInterface = {
    .Delete = Delete,
    .Id = Id,
    .Tag = Tag,
    .TemperatureSensorWatchCommand = TemperatureSensorWatchCommand,
    .State = State,
    .IsNormal = IsNormal,
};

const TemperatureSensorInterface temperatureSensor = &kTheInterface;
