// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#ifndef V1_LED_ARRAY_FACTORY_INTERFACE_H_
#define V1_LED_ARRAY_FACTORY_INTERFACE_H_

#include "led_array_interface.h"

typedef struct {
  LedArrayInterface (*Make)(int id);  //
} LedArrayFactoryInterfaceStruct;
typedef const LedArrayFactoryInterfaceStruct* LedArrayFactoryInterface;

#endif  // V1_LED_ARRAY_FACTORY_INTERFACE_H_
