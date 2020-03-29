// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#ifndef V1_DISPLAY_H_
#define V1_DISPLAY_H_

typedef struct DisplayStruct* Display;
typedef struct {
  void (*Delete)(Display* self);
  int (*Id)(Display self);
  const char* (*Tag)(Display self);
  void (*Reset)(Display self);
} DisplayInterfaceStruct;
typedef const DisplayInterfaceStruct* DisplayInterface;

extern const DisplayInterface display;

#endif  // V1_DISPLAY_H_
