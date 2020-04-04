// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#ifndef V1_NULL_PHOTOSENSOR_H_
#define V1_NULL_PHOTOSENSOR_H_

#include "photosensor.h"

typedef struct {
  Component (*GetInstance)(void);  //
} NullPhotosensorMethodStruct;
typedef const NullPhotosensorMethodStruct* NullPhotosensorMethod;

extern const NullPhotosensorMethod nullPhotosensor;

#endif  // V1_NULL_PHOTOSENSOR_H_
