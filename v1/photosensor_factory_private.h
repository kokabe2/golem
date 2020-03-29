// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#ifndef V1_PHOTOSENSOR_FACTORY_PRIVATE_H_
#define V1_PHOTOSENSOR_FACTORY_PRIVATE_H_

#include "photosensor_factory.h"

typedef struct PhotosensorFactoryStruct {
  PhotosensorFactoryInterface impl;  //
} PhotosensorFactoryStruct;

#endif  // V1_PHOTOSENSOR_FACTORY_PRIVATE_H_
