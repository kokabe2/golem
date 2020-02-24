// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#ifndef V1_TEMPERATURE_SENSOR_INTERFACE_H_
#define V1_TEMPERATURE_SENSOR_INTERFACE_H_

#include <stdbool.h>

typedef struct {
  int (*Id)(void);
  const char* (*Tag)(void);
  const char* (*State)(void);
  bool (*IsNormal)(void);
} TemperatureSensorInterfaceStruct;
typedef const TemperatureSensorInterfaceStruct* TemperatureSensorInterface;

#endif  // V1_TEMPERATURE_SENSOR_INTERFACE_H_
