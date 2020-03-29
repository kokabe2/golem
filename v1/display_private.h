// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#ifndef V1_DISPLAY_PRIVATE_H_
#define V1_DISPLAY_PRIVATE_H_

#include "display.h"

typedef struct DisplayStruct {
  DisplayInterface impl;
  int id;
  const char *tag;
} DisplayStruct;

#endif  // V1_DISPLAY_PRIVATE_H_
