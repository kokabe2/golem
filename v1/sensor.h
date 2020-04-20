// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#ifndef V1_SENSOR_H_
#define V1_SENSOR_H_

#include <stdbool.h>

#include "component.h"

typedef struct {
  void (*Delete)(Component* self);
  int (*Id)(Component self);
  const char* (*Tag)(Component self);
  const char* (*State)(Component self);
  bool (*IsDefaultState)(Component self);
} SensorInterfaceStruct;
typedef const SensorInterfaceStruct* SensorInterface;

extern const SensorInterface sensor;

#endif  // V1_SENSOR_H_
