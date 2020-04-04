// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "photosensor.h"

static void Delete(Component* self) { ((PhotosensorInterface)((*self)))->Delete(self); }

static int Id(Component self) { return ((PhotosensorInterface)self)->Id(self); }

static const char* Tag(Component self) { return ((PhotosensorInterface)self)->Tag(self); }

static const char* State(Component self) { return ((PhotosensorInterface)self)->State(self); }

static bool IsLight(Component self) { return ((PhotosensorInterface)self)->IsLight(self); }

static bool IsDark(Component self) { return ((PhotosensorInterface)self)->IsDark(self); }

static const PhotosensorInterfaceStruct kTheInterface = {
    .Delete = Delete,
    .Id = Id,
    .Tag = Tag,
    .State = State,
    .IsLight = IsLight,
    .IsDark = IsDark,
};

const PhotosensorInterface photosensor = &kTheInterface;
