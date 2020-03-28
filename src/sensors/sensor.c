// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "sensor.h"

#include "sensor_private.h"

static void Delete(Sensor* self) { (*self)->impl->Delete(self); }

static Command SensorWatchCommand(Sensor self, const char* expected_state, Command notification_command) {
  return self->impl->SensorWatchCommand(self, expected_state, notification_command);
}

static int GetId(Sensor self) { return self->impl->GetId(self); }

static const char* GetTag(Sensor self) { return self->impl->GetTag(self); }

static const char* GetState(Sensor self) { return self->impl->GetState(self); }

static bool IsDefaultState(Sensor self) { return self->impl->IsDefaultState(self); }

static const SensorInterfaceStruct kTheInterface = {
    .Delete = Delete,
    .SensorWatchCommand = SensorWatchCommand,
    .GetId = GetId,
    .GetTag = GetTag,
    .GetState = GetState,
    .IsDefaultState = IsDefaultState,
};

const SensorInterface sensor = &kTheInterface;
