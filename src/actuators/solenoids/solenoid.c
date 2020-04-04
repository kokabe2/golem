// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "solenoid.h"

#include "component_private.h"

static void Delete(Component* self) { ((SolenoidInterface)((*self)->impl))->Delete(self); }

static int Id(Component self) { return ((SolenoidInterface)(self->impl))->Id(self); }

static const char* Tag(Component self) { return ((SolenoidInterface)(self->impl))->Tag(self); }

static const char* State(Component self) { return ((SolenoidInterface)(self->impl))->State(self); }

static bool IsOn(Component self) { return ((SolenoidInterface)(self->impl))->IsOn(self); }

static Command SolenoidOnCommand(Component self) { return ((SolenoidInterface)(self->impl))->SolenoidOnCommand(self); }

static Command SolenoidOffCommand(Component self) {
  return ((SolenoidInterface)(self->impl))->SolenoidOffCommand(self);
}

static Command SolenoidForceOffCommand(Component self) {
  return ((SolenoidInterface)(self->impl))->SolenoidForceOffCommand(self);
}

static const SolenoidInterfaceStruct kTheInterface = {
    .Delete = Delete,
    .Id = Id,
    .Tag = Tag,
    .State = State,
    .IsOn = IsOn,
    .SolenoidOnCommand = SolenoidOnCommand,
    .SolenoidOffCommand = SolenoidOffCommand,
    .SolenoidForceOffCommand = SolenoidForceOffCommand,
};

const SolenoidInterface solenoid = &kTheInterface;
