// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#ifndef V1_MICROSWITCH_FACTORY_H_
#define V1_MICROSWITCH_FACTORY_H_

#include "microswitch.h"

typedef struct MicroswitchFactoryStruct* MicroswitchFactory;
typedef struct {
  void (*Delete)(MicroswitchFactory* self);
  MicroswitchInterface (*Make)(MicroswitchFactory self, int id);
} MicroswitchFactoryInterfaceStruct;
typedef const MicroswitchFactoryInterfaceStruct* MicroswitchFactoryInterface;

extern const MicroswitchFactoryInterface microswitchFactory;

#endif  // V1_MICROSWITCH_FACTORY_H_
