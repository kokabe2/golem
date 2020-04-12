// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#ifndef V1_COMPONENT_COMMAND_FACTORY_H_
#define V1_COMPONENT_COMMAND_FACTORY_H_

#include "command.h"
#include "component.h"

typedef struct ComponentCommandFactoryInterfaceStruct* ComponentCommandFactory;
typedef struct ComponentCommandFactoryInterfaceStruct {
  void (*Delete)(ComponentCommandFactory* self);
  Command (*MakeActuatorOnCommand)(ComponentCommandFactory self, Component actuator, Command next_command);
  Command (*MakeActuatorOffCommand)(ComponentCommandFactory self, Component actuator, Command next_command);
  Command (*MakeActuatorForceOffCommand)(ComponentCommandFactory self, Component actuator, Command next_command);
  Command (*MakePulseMotorStopCommand)(ComponentCommandFactory self, Component actuator, int pulse,
                                       Command notification_command);
  Command (*MakePulseMotorWatchCommand)(ComponentCommandFactory self, Component actuator, int pulse,
                                        Command notification_command);
  Command (*MakeSensorWatchCommand)(ComponentCommandFactory self, Component sensor, const char* expected_state,
                                    Command notification_command);
} ComponentCommandFactoryInterfaceStruct;
typedef const ComponentCommandFactoryInterfaceStruct* ComponentCommandFactoryInterface;

extern const ComponentCommandFactoryInterface componentCommandFactory;

#endif  // V1_COMPONENT_COMMAND_FACTORY_H_
