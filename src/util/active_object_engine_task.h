// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#ifndef SRC_UTIL_ACTIVE_OBJECT_ENGINE_TASK_H_
#define SRC_UTIL_ACTIVE_OBJECT_ENGINE_TASK_H_

#include "active_object_engine.h"

typedef struct {
  ActiveObjectEngine (*New)(void);  //
} ActiveObjectEngineTaskMethodStruct;
typedef const ActiveObjectEngineTaskMethodStruct* ActiveObjectEngineTaskMethod;

extern const ActiveObjectEngineTaskMethod activeObjectEngineTask;

#endif  // SRC_UTIL_ACTIVE_OBJECT_ENGINE_TASK_H_
