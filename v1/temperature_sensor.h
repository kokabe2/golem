// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#ifndef V1_TEMPERATURE_SENSOR_H_
#define V1_TEMPERATURE_SENSOR_H_

#include "sensor.h"

typedef struct TemperatureSensorInterfaceStruct* TemperatureSensor;
typedef struct TemperatureSensorInterfaceStruct {
  void (*Delete)(TemperatureSensor* self);
  int (*Id)(TemperatureSensor self);
  const char* (*Tag)(TemperatureSensor self);
  const char* (*State)(TemperatureSensor self);
  bool (*IsNormal)(TemperatureSensor self);
} TemperatureSensorInterfaceStruct;

#endif  // V1_TEMPERATURE_SENSOR_H_
