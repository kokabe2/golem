// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "sensor.h"

#include "sensor_private.h"

static void Delete(Sensor* self) { (*self)->impl->Delete(self); }

static int Id(Sensor self) { return self->impl->Id(self); }

static const char* Tag(Sensor self) { return self->impl->Tag(self); }

static Command SensorWatchCommand(Sensor self, const char* expected_state, Command notification_command) {
  return self->impl->SensorWatchCommand(self, expected_state, notification_command);
}

static const char* State(Sensor self) { return self->impl->State(self); }

static bool IsDefaultState(Sensor self) { return self->impl->IsDefaultState(self); }

static const SensorInterfaceStruct kTheInterface = {
    .Delete = Delete,
    .Id = Id,
    .Tag = Tag,
    .SensorWatchCommand = SensorWatchCommand,
    .State = State,
    .IsDefaultState = IsDefaultState,
};

const SensorInterface sensor = &kTheInterface;
