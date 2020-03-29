// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "actuator.h"

#include "actuator_private.h"

static void Delete(Actuator* self) { (*self)->impl->Delete(self); }

static int Id(Actuator self) { return self->impl->Id(self); }

static const char* Tag(Actuator self) { return self->impl->Tag(self); }

static const char* State(Actuator self) { return self->impl->State(self); }

static bool IsOn(Actuator self) { return self->impl->IsOn(self); }

static Command ActuatorOnCommand(Actuator self) { return self->impl->ActuatorOnCommand(self); }

static Command ActuatorOffCommand(Actuator self) { return self->impl->ActuatorOffCommand(self); }

static Command ActuatorForceOffCommand(Actuator self) { return self->impl->ActuatorForceOffCommand(self); }

static const ActuatorInterfaceStruct kTheInterface = {
    .Delete = Delete,
    .Id = Id,
    .Tag = Tag,
    .State = State,
    .IsOn = IsOn,
    .ActuatorOnCommand = ActuatorOnCommand,
    .ActuatorOffCommand = ActuatorOffCommand,
    .ActuatorForceOffCommand = ActuatorForceOffCommand,
};

const ActuatorInterface actuator = &kTheInterface;
