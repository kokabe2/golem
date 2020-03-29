// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#ifndef V1_PHOTOSENSOR_FACTORY_H_
#define V1_PHOTOSENSOR_FACTORY_H_

#include "photosensor.h"

typedef struct PhotosensorFactoryStruct* PhotosensorFactory;
typedef struct {
  void (*Delete)(PhotosensorFactory* self);
  PhotosensorInterface (*Make)(PhotosensorFactory self, int id);
} PhotosensorFactoryInterfaceStruct;
typedef const PhotosensorFactoryInterfaceStruct* PhotosensorFactoryInterface;

extern const PhotosensorFactoryInterface photosensorFactory;

#endif  // V1_PHOTOSENSOR_FACTORY_H_
