// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "null_photosensor.h"

#include <stddef.h>

#include "null_command.h"
#include "photosensor_private.h"

static PhotosensorStruct the_singleton;
static Photosensor the_instance = NULL;

static void Delete(Photosensor* self) {}

static Command NullCommand(Photosensor self, const char* expected_state, Command notification_command) {
  return nullCommand->GetInstance();
}

static int NonsenseValue(Photosensor self) { return ~0; }

static const char* EmptyString(Photosensor self) { return ""; }

static bool False(Photosensor self) { return false; }

static const PhotosensorInterfaceStruct kTheInterface = {
    .Delete = Delete,
    .SensorWatchCommand = NullCommand,
    .Id = NonsenseValue,
    .Tag = EmptyString,
    .State = EmptyString,
    .IsLight = False,
    .IsDark = False,
};

inline static Photosensor New(void) {
  the_singleton.impl = &kTheInterface;
  return &the_singleton;
}

static Photosensor GetInstance(void) {
  if (the_instance == NULL) the_instance = New();
  return the_instance;
}

static const NullPhotosensorMethodStruct kTheMethod = {
    .GetInstance = GetInstance,
};

const NullPhotosensorMethod nullPhotosensor = &kTheMethod;
