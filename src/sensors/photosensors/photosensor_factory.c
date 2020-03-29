// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "photosensor_factory.h"

#include "photosensor_factory_private.h"

static void Delete(PhotosensorFactory* self) { (*self)->impl->Delete(self); }

static PhotosensorInterface Make(PhotosensorFactory self, int id) { return self->impl->Make(self, id); }

static const PhotosensorFactoryInterfaceStruct kTheInterface = {
    .Delete = Delete,
    .Make = Make,
};

const PhotosensorFactoryInterface photosensorFactory = &kTheInterface;
