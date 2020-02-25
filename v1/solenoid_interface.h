// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#ifndef V1_SOLENOID_INTERFACE_H_
#define V1_SOLENOID_INTERFACE_H_

#include <stdbool.h>

typedef struct {
  int (*Id)(void);
  const char* (*Tag)(void);
  const char* (*State)(void);
  void (*Lock)(void);
  void (*Unlock)(void);
  bool (*IsLocked)(void);
} SolenoidInterfaceStruct;
typedef const SolenoidInterfaceStruct* SolenoidInterface;

#endif  // V1_SOLENOID_INTERFACE_H_
