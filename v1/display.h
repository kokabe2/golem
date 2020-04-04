// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#ifndef V1_DISPLAY_H_
#define V1_DISPLAY_H_

#include "component.h"

typedef struct {
  void (*Delete)(Component* self);
  int (*Id)(Component self);
  const char* (*Tag)(Component self);
  void (*Reset)(Component self);
} DisplayInterfaceStruct;
typedef const DisplayInterfaceStruct* DisplayInterface;

extern const DisplayInterface display;

#endif  // V1_DISPLAY_H_
