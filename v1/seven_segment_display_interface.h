// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#ifndef V1_SEVEN_SEGMENT_DISPLAY_INTERFACE_H_
#define V1_SEVEN_SEGMENT_DISPLAY_INTERFACE_H_

#include <stdint.h>

typedef struct {
  int (*Id)(void);
  const char* (*Tag)(void);
  void (*Clear)(void);
  uint8_t (*Get)(void);
  void (*Set)(uint8_t encoding);
} SevenSegmentDisplayInterfaceStruct;
typedef const SevenSegmentDisplayInterfaceStruct* SevenSegmentDisplayInterface;

#endif  // V1_SEVEN_SEGMENT_DISPLAY_INTERFACE_H_
