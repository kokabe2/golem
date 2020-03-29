// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#ifndef V1_SENSOR_PRIVATE_H_
#define V1_SENSOR_PRIVATE_H_

#include "sensor.h"

typedef struct SensorStruct {
  SensorInterface impl;
  int id;
  const char *tag;
} SensorStruct;

#endif  // V1_SENSOR_PRIVATE_H_
