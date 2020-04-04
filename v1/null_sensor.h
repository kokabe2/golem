// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#ifndef V1_NULL_SENSOR_H_
#define V1_NULL_SENSOR_H_

#include "sensor.h"

typedef struct {
  Component (*GetInstance)(void);  //
} NullSensorMethodStruct;
typedef const NullSensorMethodStruct* NullSensorMethod;

extern const NullSensorMethod nullSensor;

#endif  // V1_NULL_SENSOR_H_
