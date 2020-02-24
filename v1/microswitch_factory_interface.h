// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#ifndef V1_MICROSWITCH_FACTORY_INTERFACE_H_
#define V1_MICROSWITCH_FACTORY_INTERFACE_H_

#include "microswitch_interface.h"

typedef struct {
  MicroswitchInterface (*Make)(int id);
} MicroswitchFactoryInterfaceStruct;
typedef const MicroswitchFactoryInterfaceStruct* MicroswitchFactoryInterface;

#endif  // V1_MICROSWITCH_FACTORY_INTERFACE_H_
