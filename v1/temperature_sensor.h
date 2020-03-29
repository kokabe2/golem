// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#ifndef V1_TEMPERATURE_SENSOR_H_
#define V1_TEMPERATURE_SENSOR_H_

#include <stdbool.h>

#include "command.h"

typedef struct TemperatureSensorStruct* TemperatureSensor;
typedef struct {
  void (*Delete)(TemperatureSensor* self);
  int (*Id)(TemperatureSensor self);
  const char* (*Tag)(TemperatureSensor self);
  Command (*TemperatureSensorWatchCommand)(TemperatureSensor self, const char* expected_state,
                                           Command notification_command);
  const char* (*State)(TemperatureSensor self);
  bool (*IsNormal)(TemperatureSensor self);
} TemperatureSensorInterfaceStruct;
typedef const TemperatureSensorInterfaceStruct* TemperatureSensorInterface;

extern const TemperatureSensorInterface temperatureSensor;

#endif  // V1_TEMPERATURE_SENSOR_H_
