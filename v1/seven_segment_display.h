// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#ifndef V1_SEVEN_SEGMENT_DISPLAY_H_
#define V1_SEVEN_SEGMENT_DISPLAY_H_

#include <stdint.h>

typedef struct SevenSegmentDisplayStruct* SevenSegmentDisplay;
typedef struct {
  void (*Delete)(SevenSegmentDisplay* self);
  int (*Id)(SevenSegmentDisplay self);
  const char* (*Tag)(SevenSegmentDisplay self);
  void (*Clear)(SevenSegmentDisplay self);
  uint8_t (*Get)(SevenSegmentDisplay self);
  void (*Set)(SevenSegmentDisplay self, uint8_t encoding);
} SevenSegmentDisplayInterfaceStruct;
typedef const SevenSegmentDisplayInterfaceStruct* SevenSegmentDisplayInterface;

extern const SevenSegmentDisplayInterface sevenSegmentDisplay;

#endif  // V1_SEVEN_SEGMENT_DISPLAY_H_
