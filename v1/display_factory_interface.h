// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#ifndef V1_DISPLAY_FACTORY_INTERFACE_H_
#define V1_DISPLAY_FACTORY_INTERFACE_H_

#include "display_interface.h"

typedef struct {
  DisplayInterface (*Make)(int id);  //
} DisplayFactoryInterfaceStruct;
typedef const DisplayFactoryInterfaceStruct* DisplayFactoryInterface;

#endif  // V1_DISPLAY_FACTORY_INTERFACE_H_
