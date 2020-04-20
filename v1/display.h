// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#ifndef V1_DISPLAY_H_
#define V1_DISPLAY_H_

#include "component.h"

typedef struct DisplayInterfaceStruct* Display;
typedef struct DisplayInterfaceStruct {
  void (*Delete)(Display* self);
  int (*Id)(Display self);
  const char* (*Tag)(Display self);
  void (*Reset)(Display self);
} DisplayInterfaceStruct;

#endif  // V1_DISPLAY_H_
