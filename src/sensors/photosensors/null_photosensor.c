// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "null_photosensor.h"

#include <stddef.h>

#include "component_private.h"
#include "null_command.h"

static ComponentStruct the_singleton;
static Component the_instance = NULL;

static void Delete(Component* self) {}

static int NonsenseValue(Component self) { return ~0; }

static const char* EmptyString(Component self) { return ""; }

static Command NullCommand(Component self, const char* expected_state, Command notification_command) {
  return nullCommand->GetInstance();
}

static bool False(Component self) { return false; }

static const PhotosensorInterfaceStruct kTheInterface = {
    .Delete = Delete,
    .Id = NonsenseValue,
    .Tag = EmptyString,
    .PhotosensorWatchCommand = NullCommand,
    .State = EmptyString,
    .IsLight = False,
    .IsDark = False,
};

inline static Component New(void) {
  the_singleton.impl = (ComponentInterface)&kTheInterface;
  return &the_singleton;
}

static Component GetInstance(void) {
  if (the_instance == NULL) the_instance = New();
  return the_instance;
}

static const NullPhotosensorMethodStruct kTheMethod = {
    .GetInstance = GetInstance,
};

const NullPhotosensorMethod nullPhotosensor = &kTheMethod;
