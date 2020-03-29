// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "photosensor.h"

#include "photosensor_private.h"

static void Delete(Photosensor* self) { (*self)->impl->Delete(self); }

static int Id(Photosensor self) { return self->impl->Id(self); }

static const char* Tag(Photosensor self) { return self->impl->Tag(self); }

static Command PhotosensorWatchCommand(Photosensor self, const char* expected_state, Command notification_command) {
  return self->impl->PhotosensorWatchCommand(self, expected_state, notification_command);
}

static const char* State(Photosensor self) { return self->impl->State(self); }

static bool IsLight(Photosensor self) { return self->impl->IsLight(self); }

static bool IsDark(Photosensor self) { return self->impl->IsDark(self); }

static const PhotosensorInterfaceStruct kTheInterface = {
    .Delete = Delete,
    .Id = Id,
    .Tag = Tag,
    .PhotosensorWatchCommand = PhotosensorWatchCommand,
    .State = State,
    .IsLight = IsLight,
    .IsDark = IsDark,
};

const PhotosensorInterface photosensor = &kTheInterface;
