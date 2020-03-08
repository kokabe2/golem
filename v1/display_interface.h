// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#ifndef V1_DISPLAY_INTERFACE_H_
#define V1_DISPLAY_INTERFACE_H_

typedef struct {
  int (*Id)(void);
  const char* (*Tag)(void);
  void (*Reset)(void);
} DisplayInterfaceStruct;
typedef const DisplayInterfaceStruct* DisplayInterface;

#endif  // V1_DISPLAY_INTERFACE_H_
