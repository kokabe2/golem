// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#ifndef V1_LED_FACTORY_INTERFACE_H_
#define V1_LED_FACTORY_INTERFACE_H_

#include "led_interface.h"

typedef struct {
  LedInterface (*Make)(int id);  //
} LedFactoryInterfaceStruct;
typedef const LedFactoryInterfaceStruct* LedFactoryInterface;

#endif  // V1_LED_FACTORY_INTERFACE_H_
