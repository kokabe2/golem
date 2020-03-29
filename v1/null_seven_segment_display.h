// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#ifndef V1_NULL_SEVEN_SEGMENT_DISPLAY_H_
#define V1_NULL_SEVEN_SEGMENT_DISPLAY_H_

#include "seven_segment_display.h"

typedef struct {
  SevenSegmentDisplay (*GetInstance)(void);  //
} NullSevenSegmentDisplayMethodStruct;
typedef const NullSevenSegmentDisplayMethodStruct* NullSevenSegmentDisplayMethod;

extern const NullSevenSegmentDisplayMethod nullSevenSegmentDisplay;

#endif  // V1_NULL_SEVEN_SEGMENT_DISPLAY_H_
