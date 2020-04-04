// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "null_pulse_motor.h"

#include <stddef.h>

#include "null_command.h"

static Component the_instance = NULL;

static void Delete(Component* self) {}

static int NonsenseValue(Component self) { return ~0; }

static const char* EmptyString(Component self) { return ""; }

static bool False(Component self) { return false; }

static Command NullCommand(Component self) { return nullCommand->GetInstance(); }

static void NoEffectWithString(Component self, const char* direction) {}

static int Zero(Component self) { return 0; }

static void NoEffectWithInt(Component self, int rpm) {}

static Command NullCommandWithInt(Component self, int pulse) { return nullCommand->GetInstance(); }

static Command NullCommandWithIntAndCommand(Component self, int pulse, Command notification_command) {
  return nullCommand->GetInstance();
}

static const PulseMotorInterfaceStruct kTheInterface = {
    .Delete = Delete,
    .Id = NonsenseValue,
    .Tag = EmptyString,
    .State = EmptyString,
    .IsOn = False,
    .PulseMotorOnCommand = NullCommand,
    .PulseMotorOffCommand = NullCommand,
    .PulseMotorForceOffCommand = NullCommand,
    .GetDirection = EmptyString,
    .SetDirection = NoEffectWithString,
    .GetSpeed = Zero,
    .SetSpeed = NoEffectWithInt,
    .PulseMotorStopCommand = NullCommandWithInt,
    .PulseMotorWatchCommand = NullCommandWithIntAndCommand,
    .GetMode = EmptyString,
    .SelectMode = NoEffectWithString,
    .GetPulseRate = Zero,
    .SetPulseRate = NoEffectWithInt,
    .GetPosition = Zero,
};

inline static Component New(void) { return (Component)&kTheInterface; }

static Component GetInstance(void) {
  if (the_instance == NULL) the_instance = New();
  return the_instance;
}

static const NullPulseMotorMethodStruct kTheMethod = {
    .GetInstance = GetInstance,
};

const NullPulseMotorMethod nullPulseMotor = &kTheMethod;
