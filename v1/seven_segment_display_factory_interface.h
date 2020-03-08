// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#ifndef V1_SEVEN_SEGMENT_DISPLAY_FACTORY_INTERFACE_H_
#define V1_SEVEN_SEGMENT_DISPLAY_FACTORY_INTERFACE_H_

#include "seven_segment_display_interface.h"

typedef struct {
  SevenSegmentDisplayInterface (*Make)(int id);  //
} SevenSegmentDisplayFactoryInterfaceStruct;
typedef const SevenSegmentDisplayFactoryInterfaceStruct* SevenSegmentDisplayFactoryInterface;

#endif  // V1_SEVEN_SEGMENT_DISPLAY_FACTORY_INTERFACE_H_
