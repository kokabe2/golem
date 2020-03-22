// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#ifndef SRC_UTIL_ACTIVE_OBJECT_ENGINE_PROTECTED_H_
#define SRC_UTIL_ACTIVE_OBJECT_ENGINE_PROTECTED_H_

#include "active_object_engine.h"

typedef struct {
  void (*DoCommand)(ActiveObjectEngine self);  //
} ActiveObjectEngineProtectedMethodStruct;
typedef const ActiveObjectEngineProtectedMethodStruct* ActiveObjectEngineProtectedMethod;

extern const ActiveObjectEngineProtectedMethod _activeObjectEngine;

#endif  // SRC_UTIL_ACTIVE_OBJECT_ENGINE_PROTECTED_H_
