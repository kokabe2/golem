// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "null_solenoid.h"

#include <stddef.h>

#include "null_command.h"
#include "solenoid_private.h"

static SolenoidStruct the_singleton;
static Solenoid the_instance = NULL;

static void Delete(Solenoid* self) {}

static int NonsenseValue(Solenoid self) { return ~0; }

static const char* EmptyString(Solenoid self) { return ""; }

static bool False(Solenoid self) { return false; }

static Command NullCommand(Solenoid self) { return nullCommand->GetInstance(); }

static const SolenoidInterfaceStruct kTheInterface = {
    .Delete = Delete,
    .Id = NonsenseValue,
    .Tag = EmptyString,
    .State = EmptyString,
    .IsOn = False,
    .SolenoidOnCommand = NullCommand,
    .SolenoidOffCommand = NullCommand,
    .SolenoidForceOffCommand = NullCommand,
};

inline static Solenoid New(void) {
  the_singleton.impl = &kTheInterface;
  return &the_singleton;
}

static Solenoid GetInstance(void) {
  if (the_instance == NULL) the_instance = New();
  return the_instance;
}

static const NullSolenoidMethodStruct kTheMethod = {
    .GetInstance = GetInstance,
};

const NullSolenoidMethod nullSolenoid = &kTheMethod;
