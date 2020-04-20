// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#ifndef V1_PHOTOSENSOR_H_
#define V1_PHOTOSENSOR_H_

#include "sensor.h"

typedef struct PhotosensorInterfaceStruct* Photosensor;
typedef struct PhotosensorInterfaceStruct {
  void (*Delete)(Photosensor* self);
  int (*Id)(Photosensor self);
  const char* (*Tag)(Photosensor self);
  const char* (*State)(Photosensor self);
  bool (*IsLight)(Photosensor self);
  bool (*IsDark)(Photosensor self);
} PhotosensorInterfaceStruct;

#endif  // V1_PHOTOSENSOR_H_
