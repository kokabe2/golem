// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "component_command_factory.h"

static void Delete(ComponentCommandFactory* self) { (*self)->Delete(self); }

static Command MakeActuatorOnCommand(ComponentCommandFactory self, Component actuator) {
  return self->MakeActuatorOnCommand(self, actuator);
}

static Command MakeActuatorOffCommand(ComponentCommandFactory self, Component actuator) {
  return self->MakeActuatorOffCommand(self, actuator);
}

static Command MakeActuatorForceOffCommand(ComponentCommandFactory self, Component actuator) {
  return self->MakeActuatorForceOffCommand(self, actuator);
}

static Command MakePulseMotorStopCommand(ComponentCommandFactory self, Component actuator, int pulse) {
  return self->MakePulseMotorStopCommand(self, actuator, pulse);
}

static Command MakePulseMotorWatchCommand(ComponentCommandFactory self, Component actuator, int pulse,
                                          Command notification_command) {
  return self->MakePulseMotorWatchCommand(self, actuator, pulse, notification_command);
}

static Command MakeSensorWatchCommand(ComponentCommandFactory self, Component sensor, const char* expected_state,
                                      Command notification_command) {
  return self->MakeSensorWatchCommand(self, sensor, expected_state, notification_command);
}

static const ComponentCommandFactoryInterfaceStruct kTheInterface = {
    .Delete = Delete,
    .MakeActuatorOnCommand = MakeActuatorOnCommand,
    .MakeActuatorOffCommand = MakeActuatorOffCommand,
    .MakeActuatorForceOffCommand = MakeActuatorForceOffCommand,
    .MakePulseMotorStopCommand = MakePulseMotorStopCommand,
    .MakePulseMotorWatchCommand = MakePulseMotorWatchCommand,
    .MakeSensorWatchCommand = MakeSensorWatchCommand,
};

const ComponentCommandFactoryInterface componentCommandFactory = &kTheInterface;
