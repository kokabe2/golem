// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "actuator.h"

#include "component_private.h"

static void Delete(Component* self) { ((ActuatorInterface)((*self)->impl))->Delete(self); }

static int Id(Component self) { return ((ActuatorInterface)(self->impl))->Id(self); }

static const char* Tag(Component self) { return ((ActuatorInterface)(self->impl))->Tag(self); }

static const char* State(Component self) { return ((ActuatorInterface)(self->impl))->State(self); }

static bool IsOn(Component self) { return ((ActuatorInterface)(self->impl))->IsOn(self); }

static Command ActuatorOnCommand(Component self) { return ((ActuatorInterface)(self->impl))->ActuatorOnCommand(self); }

static Command ActuatorOffCommand(Component self) {
  return ((ActuatorInterface)(self->impl))->ActuatorOffCommand(self);
}

static Command ActuatorForceOffCommand(Component self) {
  return ((ActuatorInterface)(self->impl))->ActuatorForceOffCommand(self);
}

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
