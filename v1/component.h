// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#ifndef V1_COMPONENT_H_
#define V1_COMPONENT_H_

typedef struct ComponentStruct* Component;
typedef struct {
  void (*Delete)(Component* self);
  int (*Id)(Component self);
  const char* (*Tag)(Component self);
} ComponentInterfaceStruct;
typedef const ComponentInterfaceStruct* ComponentInterface;

extern const ComponentInterface component;

#endif  // V1_COMPONENT_H_
