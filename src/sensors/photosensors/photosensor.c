// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "photosensor.h"

#include "component_private.h"

static void Delete(Component* self) { ((PhotosensorInterface)((*self)->impl))->Delete(self); }

static int Id(Component self) { return ((PhotosensorInterface)(self->impl))->Id(self); }

static const char* Tag(Component self) { return ((PhotosensorInterface)(self->impl))->Tag(self); }

static Command PhotosensorWatchCommand(Component self, const char* expected_state, Command notification_command) {
  return ((PhotosensorInterface)(self->impl))->PhotosensorWatchCommand(self, expected_state, notification_command);
}

static const char* State(Component self) { return ((PhotosensorInterface)(self->impl))->State(self); }

static bool IsLight(Component self) { return ((PhotosensorInterface)(self->impl))->IsLight(self); }

static bool IsDark(Component self) { return ((PhotosensorInterface)(self->impl))->IsDark(self); }

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
