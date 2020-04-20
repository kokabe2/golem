// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#ifndef V1_SENSOR_H_
#define V1_SENSOR_H_

#include <stdbool.h>

#include "component.h"

typedef struct SensorInterfaceStruct* Sensor;
typedef struct SensorInterfaceStruct {
  void (*Delete)(Sensor* self);
  int (*Id)(Sensor self);
  const char* (*Tag)(Sensor self);
  const char* (*State)(Sensor self);
  bool (*IsDefaultState)(Sensor self);
} SensorInterfaceStruct;

#endif  // V1_SENSOR_H_
