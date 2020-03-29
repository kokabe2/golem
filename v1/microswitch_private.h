// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#ifndef V1_MICROSWITCH_PRIVATE_H_
#define V1_MICROSWITCH_PRIVATE_H_

#include "microswitch.h"

typedef struct MicroswitchStruct {
  MicroswitchInterface impl;
  int id;
  const char *tag;
} MicroswitchStruct;

#endif  // V1_MICROSWITCH_PRIVATE_H_
