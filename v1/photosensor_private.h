// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#ifndef V1_PHOTOSENSOR_PRIVATE_H_
#define V1_PHOTOSENSOR_PRIVATE_H_

#include "photosensor.h"

typedef struct PhotosensorStruct {
  PhotosensorInterface impl;
  int id;
  const char *tag;
} PhotosensorStruct;

#endif  // V1_PHOTOSENSOR_PRIVATE_H_
