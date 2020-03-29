// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#ifndef V1_PHOTOSENSOR_H_
#define V1_PHOTOSENSOR_H_

#include <stdbool.h>

#include "command.h"

typedef struct PhotosensorStruct* Photosensor;
typedef struct {
  void (*Delete)(Photosensor* self);
  int (*Id)(Photosensor self);
  const char* (*Tag)(Photosensor self);
  Command (*SensorWatchCommand)(Photosensor self, const char* expected_state, Command notification_command);
  const char* (*State)(Photosensor self);
  bool (*IsLight)(Photosensor self);
  bool (*IsDark)(Photosensor self);
} PhotosensorInterfaceStruct;
typedef const PhotosensorInterfaceStruct* PhotosensorInterface;

extern const PhotosensorInterface photosensor;

#endif  // V1_PHOTOSENSOR_H_
