// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#ifndef V1_PHOTOSENSOR_H_
#define V1_PHOTOSENSOR_H_

#include <stdbool.h>

#include "command.h"
#include "component.h"

typedef struct {
  void (*Delete)(Component* self);
  int (*Id)(Component self);
  const char* (*Tag)(Component self);
  Command (*PhotosensorWatchCommand)(Component self, const char* expected_state, Command notification_command);
  const char* (*State)(Component self);
  bool (*IsLight)(Component self);
  bool (*IsDark)(Component self);
} PhotosensorInterfaceStruct;
typedef const PhotosensorInterfaceStruct* PhotosensorInterface;

extern const PhotosensorInterface photosensor;

#endif  // V1_PHOTOSENSOR_H_
