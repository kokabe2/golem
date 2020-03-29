// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "solenoid.h"

#include "solenoid_private.h"

static void Delete(Solenoid* self) { (*self)->impl->Delete(self); }

static int Id(Solenoid self) { return self->impl->Id(self); }

static const char* Tag(Solenoid self) { return self->impl->Tag(self); }

static const char* State(Solenoid self) { return self->impl->State(self); }

static bool IsOn(Solenoid self) { return self->impl->IsOn(self); }

static Command SolenoidOnCommand(Solenoid self) { return self->impl->SolenoidOnCommand(self); }

static Command SolenoidOffCommand(Solenoid self) { return self->impl->SolenoidOffCommand(self); }

static Command SolenoidForceOffCommand(Solenoid self) { return self->impl->SolenoidForceOffCommand(self); }

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
