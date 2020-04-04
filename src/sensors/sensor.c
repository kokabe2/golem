// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "sensor.h"

#include "component_private.h"

static void Delete(Component* self) { ((SensorInterface)(*self)->impl)->Delete(self); }

static int Id(Component self) { return ((SensorInterface)(self->impl))->Id(self); }

static const char* Tag(Component self) { return ((SensorInterface)(self->impl))->Tag(self); }

static Command SensorWatchCommand(Component self, const char* expected_state, Command notification_command) {
  return ((SensorInterface)(self->impl))->SensorWatchCommand(self, expected_state, notification_command);
}

static const char* State(Component self) { return ((SensorInterface)(self->impl))->State(self); }

static bool IsDefaultState(Component self) { return ((SensorInterface)(self->impl))->IsDefaultState(self); }

static const SensorInterfaceStruct kTheInterface = {
    .Delete = Delete,
    .Id = Id,
    .Tag = Tag,
    .SensorWatchCommand = SensorWatchCommand,
    .State = State,
    .IsDefaultState = IsDefaultState,
};

const SensorInterface sensor = &kTheInterface;
