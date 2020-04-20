// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#ifndef V1_NULL_TEMPERATURE_SENSOR_H_
#define V1_NULL_TEMPERATURE_SENSOR_H_

#include "temperature_sensor.h"

typedef struct {
  TemperatureSensor (*GetInstance)(void);  //
} NullTemperatureSensorMethodStruct;
typedef const NullTemperatureSensorMethodStruct* NullTemperatureSensorMethod;

extern const NullTemperatureSensorMethod nullTemperatureSensor;

#endif  // V1_NULL_TEMPERATURE_SENSOR_H_
