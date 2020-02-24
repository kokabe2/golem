// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#ifndef V1_PHOTOSENSOR_INTERFACE_H_
#define V1_PHOTOSENSOR_INTERFACE_H_

#include <stdbool.h>

typedef struct {
  int (*Id)(void);
  const char* (*Tag)(void);
  const char* (*State)(void);
  bool (*IsLight)(void);
  bool (*IsDark)(void);
} PhotosensorInterfaceStruct;
typedef const PhotosensorInterfaceStruct* PhotosensorInterface;

#endif  // V1_PHOTOSENSOR_INTERFACE_H_
