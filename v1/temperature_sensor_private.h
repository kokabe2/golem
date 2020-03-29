// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#ifndef V1_TEMPERATURE_SENSOR_PRIVATE_H_
#define V1_TEMPERATURE_SENSOR_PRIVATE_H_

#include "temperature_sensor.h"

typedef struct TemperatureSensorStruct {
  TemperatureSensorInterface impl;
  int id;
  const char *tag;
} TemperatureSensorStruct;

#endif  // V1_TEMPERATURE_SENSOR_PRIVATE_H_
