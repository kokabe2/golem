// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#ifndef V1_SENSOR_FACTORY_H_
#define V1_SENSOR_FACTORY_H_

#include "sensor.h"

typedef struct SensorFactoryStruct* SensorFactory;
typedef struct {
  void (*Delete)(SensorFactory* self);
  SensorInterface (*Make)(SensorFactory self, int id);
} SensorFactoryInterfaceStruct;
typedef const SensorFactoryInterfaceStruct* SensorFactoryInterface;

extern const SensorFactoryInterface sensorFactory;

#endif  // V1_SENSOR_FACTORY_H_
