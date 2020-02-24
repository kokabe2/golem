// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#ifndef V1_MICROSWITCH_INTERFACE_H_
#define V1_MICROSWITCH_INTERFACE_H_

#include <stdbool.h>

typedef struct {
  int (*Id)(void);
  const char* (*Tag)(void);
  const char* (*State)(void);
  bool (*IsOff)(void);
  bool (*IsOn)(void);
} MicroswitchInterfaceStruct;
typedef const MicroswitchInterfaceStruct* MicroswitchInterface;

#endif  // V1_MICROSWITCH_INTERFACE_H_
