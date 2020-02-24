// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#ifndef V1_TEMPERATURE_SENSOR_FACTORY_INTERFACE_H_
#define V1_TEMPERATURE_SENSOR_FACTORY_INTERFACE_H_

#include "temperature_sensor_interface.h"

typedef struct {
  TemperatureSensorInterface (*Make)(int id);
} TemperatureSensorFactoryInterfaceStruct;
typedef const TemperatureSensorFactoryInterfaceStruct*
    TemperatureSensorFactoryInterface;

#endif  // V1_TEMPERATURE_SENSOR_FACTORY_INTERFACE_H_
