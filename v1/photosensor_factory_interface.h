// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#ifndef V1_PHOTOSENSOR_FACTORY_INTERFACE_H_
#define V1_PHOTOSENSOR_FACTORY_INTERFACE_H_

#include "photosensor_interface.h"

typedef struct {
  PhotosensorInterface (*Make)(int id);
} PhotosensorFactoryInterfaceStruct;
typedef const PhotosensorFactoryInterfaceStruct* PhotosensorFactoryInterface;

#endif  // V1_PHOTOSENSOR_FACTORY_INTERFACE_H_
