// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#ifndef V1_SENSOR_FACTORY_PRIVATE_H_
#define V1_SENSOR_FACTORY_PRIVATE_H_

#include "sensor_factory.h"

typedef struct SensorFactoryStruct {
  SensorFactoryInterface impl;  //
} SensorFactoryStruct;

#endif  // V1_SENSOR_FACTORY_PRIVATE_H_
