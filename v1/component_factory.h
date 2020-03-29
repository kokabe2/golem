// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#ifndef V1_COMPONENT_FACTORY_H_
#define V1_COMPONENT_FACTORY_H_

#include "component.h"

typedef struct ComponentFactoryStruct* ComponentFactory;
typedef struct {
  void (*Delete)(ComponentFactory* self);
  Component (*Make)(ComponentFactory self, int id);
} ComponentFactoryInterfaceStruct;
typedef const ComponentFactoryInterfaceStruct* ComponentFactoryInterface;

extern const ComponentFactoryInterface componentFactory;

#endif  // V1_COMPONENT_FACTORY_H_
