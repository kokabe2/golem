// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#ifndef V1_SENSOR_FACTORY_INTERFACE_H_
#define V1_SENSOR_FACTORY_INTERFACE_H_

#include "sensor_interface.h"

typedef struct {
  SensorInterface (*Make)(int id);
} SensorFactoryInterfaceStruct;
typedef const SensorFactoryInterfaceStruct* SensorFactoryInterface;

#endif  // V1_SENSOR_FACTORY_INTERFACE_H_
