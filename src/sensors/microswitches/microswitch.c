// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "microswitch.h"

#include "microswitch_private.h"

static void Delete(Microswitch* self) { (*self)->impl->Delete(self); }

static int Id(Microswitch self) { return self->impl->Id(self); }

static const char* Tag(Microswitch self) { return self->impl->Tag(self); }

static Command SensorWatchCommand(Microswitch self, const char* expected_state, Command notification_command) {
  return self->impl->SensorWatchCommand(self, expected_state, notification_command);
}

static const char* State(Microswitch self) { return self->impl->State(self); }

static bool IsOff(Microswitch self) { return self->impl->IsOff(self); }

static bool IsOn(Microswitch self) { return self->impl->IsOn(self); }

static const MicroswitchInterfaceStruct kTheInterface = {
    .Delete = Delete,
    .Id = Id,
    .Tag = Tag,
    .SensorWatchCommand = SensorWatchCommand,
    .State = State,
    .IsOff = IsOff,
    .IsOn = IsOn,
};

const MicroswitchInterface microswitch = &kTheInterface;
