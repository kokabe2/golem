// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "null_photosensor.h"

#include <stddef.h>

#include "bleu/v1/heap.h"

static Photosensor INSTANCE = NULL;

static void Delete(Photosensor* self) {}

static int NonsenseValue(Photosensor self) { return ~0; }

static const char* EmptyString(Photosensor self) { return ""; }

static bool False(Photosensor self) { return false; }

inline static Photosensor New(void) {
  Photosensor self = heap->New(sizeof(PhotosensorInterfaceStruct));
  self->Delete = Delete;
  self->Id = NonsenseValue;
  self->Tag = EmptyString;
  self->State = EmptyString;
  self->IsLight = False;
  self->IsDark = False;
  return self;
}

static Photosensor GetInstance(void) {
  if (INSTANCE == NULL) INSTANCE = New();
  return INSTANCE;
}

static const NullPhotosensorMethodStruct kTheMethod = {
    .GetInstance = GetInstance,
};

const NullPhotosensorMethod nullPhotosensor = &kTheMethod;
