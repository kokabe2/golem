// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "null_microswitch.h"

#include <stddef.h>

#include "microswitch_private.h"
#include "null_command.h"

static MicroswitchStruct the_singleton;
static Microswitch the_instance = NULL;

static void Delete(Microswitch* self) {}

static int NonsenseValue(Microswitch self) { return ~0; }

static const char* EmptyString(Microswitch self) { return ""; }

static Command NullCommand(Microswitch self, const char* expected_state, Command notification_command) {
  return nullCommand->GetInstance();
}

static bool False(Microswitch self) { return false; }

static const MicroswitchInterfaceStruct kTheInterface = {
    .Delete = Delete,
    .Id = NonsenseValue,
    .Tag = EmptyString,
    .MicroswitchWatchCommand = NullCommand,
    .State = EmptyString,
    .IsOff = False,
    .IsOn = False,
};

inline static Microswitch New(void) {
  the_singleton.impl = &kTheInterface;
  return &the_singleton;
}

static Microswitch GetInstance(void) {
  if (the_instance == NULL) the_instance = New();
  return the_instance;
}

static const NullMicroswitchMethodStruct kTheMethod = {
    .GetInstance = GetInstance,
};

const NullMicroswitchMethod nullMicroswitch = &kTheMethod;
