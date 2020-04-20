// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#ifndef V1_COMPONENT_FACTORY_H_
#define V1_COMPONENT_FACTORY_H_

#include "component.h"

typedef struct ComponentFactoryInterfaceStruct* ComponentFactory;
typedef struct ComponentFactoryInterfaceStruct {
  void (*Delete)(ComponentFactory* self);
  Component (*Make)(ComponentFactory self, const char* component_name, int id);
} ComponentFactoryInterfaceStruct;

#endif  // V1_COMPONENT_FACTORY_H_
