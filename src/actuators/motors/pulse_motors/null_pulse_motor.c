// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "null_pulse_motor.h"

#include <stddef.h>

#include "null_command.h"
#include "pulse_motor_private.h"

static PulseMotorStruct the_singleton;
static PulseMotor the_instance = NULL;

static void Delete(PulseMotor* self) {}

static int NonsenseValue(PulseMotor self) { return ~0; }

static const char* EmptyString(PulseMotor self) { return ""; }

static bool False(PulseMotor self) { return false; }

static Command NullCommand(PulseMotor self) { return nullCommand->GetInstance(); }

static void NoEffectWithString(PulseMotor self, const char* direction) {}

static int Zero(PulseMotor self) { return 0; }

static void NoEffectWithInt(PulseMotor self, int rpm) {}

static Command NullCommandWithInt(PulseMotor self, int pulse) { return nullCommand->GetInstance(); }

static Command NullCommandWithIntAndCommand(PulseMotor self, int pulse, Command notification_command) {
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

inline static PulseMotor New(void) {
  the_singleton.impl = &kTheInterface;
  return &the_singleton;
}

static PulseMotor GetInstance(void) {
  if (the_instance == NULL) the_instance = New();
  return the_instance;
}

static const NullPulseMotorMethodStruct kTheMethod = {
    .GetInstance = GetInstance,
};

const NullPulseMotorMethod nullPulseMotor = &kTheMethod;
