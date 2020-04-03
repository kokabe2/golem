// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#ifndef V1_SIMPLE_ACTIVE_OBJECT_ENGINE_H_
#define V1_SIMPLE_ACTIVE_OBJECT_ENGINE_H_

#include "active_object_engine.h"

typedef struct {
  ActiveObjectEngine (*New)(void);  //
} SimpleActiveObjectEngineMethodStruct;
typedef const SimpleActiveObjectEngineMethodStruct* SimpleActiveObjectEngineMethod;

extern const SimpleActiveObjectEngineMethod simpleActiveObjectEngine;

#endif  // V1_SIMPLE_ACTIVE_OBJECT_ENGINE_H_
