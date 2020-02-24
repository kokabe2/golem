// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#ifndef V1_SENSOR_INTERFACE_H_
#define V1_SENSOR_INTERFACE_H_

#include <stdbool.h>

typedef struct {
  int (*Id)(void);
  const char* (*Tag)(void);
  const char* (*State)(void);
  bool (*IsDefaultState)(void);
} SensorInterfaceStruct;
typedef const SensorInterfaceStruct* SensorInterface;

#endif  // V1_SENSOR_INTERFACE_H_
