// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#ifndef V1_SEVEN_SEGMENT_DISPLAY_PRIVATE_H_
#define V1_SEVEN_SEGMENT_DISPLAY_PRIVATE_H_

#include "seven_segment_display.h"

typedef struct SevenSegmentDisplayStruct {
  SevenSegmentDisplayInterface impl;
  int id;
  const char *tag;
} SevenSegmentDisplayStruct;

#endif  // V1_SEVEN_SEGMENT_DISPLAY_PRIVATE_H_
