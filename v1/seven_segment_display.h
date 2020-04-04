// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#ifndef V1_SEVEN_SEGMENT_DISPLAY_H_
#define V1_SEVEN_SEGMENT_DISPLAY_H_

#include <stdint.h>

#include "component.h"

typedef struct {
  void (*Delete)(Component* self);
  int (*Id)(Component self);
  const char* (*Tag)(Component self);
  void (*Clear)(Component self);
  uint8_t (*Get)(Component self);
  void (*Set)(Component self, uint8_t encoding);
} SevenSegmentDisplayInterfaceStruct;
typedef const SevenSegmentDisplayInterfaceStruct* SevenSegmentDisplayInterface;

extern const SevenSegmentDisplayInterface sevenSegmentDisplay;

#endif  // V1_SEVEN_SEGMENT_DISPLAY_H_
