// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "null_photosensor.h"

static int Id(void) { return ~0; }

static const char* Tag(void) { return ""; }

static const char* State(void) { return ""; }

static bool IsLight(void) { return false; }

static bool IsDark(void) { return false; }

static const PhotosensorInterfaceStruct kTheMethod = {
    .Id = Id, .Tag = Tag, .State = State, .IsLight = IsLight, .IsDark = IsDark,
};

const PhotosensorInterface nullPhotosensor = &kTheMethod;
