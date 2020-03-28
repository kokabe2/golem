// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#ifndef V1_SENSOR_H_
#define V1_SENSOR_H_

#include <stdbool.h>

#include "command.h"

typedef struct SensorStruct* Sensor;
typedef struct {
  void (*Delete)(Sensor* self);
  Command (*SensorWatchCommand)(Sensor self, const char* expected_state, Command notification_command);
  int (*Id)(Sensor self);
  const char* (*Tag)(Sensor self);
  const char* (*State)(Sensor self);
  bool (*IsDefaultState)(Sensor self);
} SensorInterfaceStruct;
typedef const SensorInterfaceStruct* SensorInterface;

extern const SensorInterface sensor;

#endif  // V1_SENSOR_H_
