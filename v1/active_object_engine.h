// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#ifndef V1_ACTIVE_OBJECT_ENGINE_H_
#define V1_ACTIVE_OBJECT_ENGINE_H_

#include "command.h"

typedef struct ActiveObjectEngineStruct* ActiveObjectEngine;
typedef struct {
  ActiveObjectEngine (*GetInstance)(void);
  void (*Delete)(ActiveObjectEngine* self);
  void (*Run)(ActiveObjectEngine self);
  void (*AddCommand)(ActiveObjectEngine self, Command c);
} ActiveObjectEngineMethodStruct;
typedef const ActiveObjectEngineMethodStruct* ActiveObjectEngineMethod;

extern const ActiveObjectEngineMethod activeObjectEngine;

#endif  // V1_ACTIVE_OBJECT_ENGINE_H_
