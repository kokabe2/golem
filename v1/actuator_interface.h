// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#ifndef V1_ACTUATOR_INTERFACE_H_
#define V1_ACTUATOR_INTERFACE_H_

#include <stdbool.h>

typedef struct {
  int (*Id)(void);
  const char* (*Tag)(void);
  const char* (*State)(void);
  void (*Activate)(void);
  void (*Deactivate)(void);
  bool (*IsActive)(void);
} ActuatorInterfaceStruct;
typedef const ActuatorInterfaceStruct* ActuatorInterface;

#endif  // V1_ACTUATOR_INTERFACE_H_
