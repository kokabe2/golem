// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#ifndef V1_SCRIPT_H_
#define V1_SCRIPT_H_

#include <stdbool.h>

#include "active_object_engine.h"

typedef struct ScriptStruct *Script;
typedef struct {
  void (*Delete)(Script *self);
  void (*Run)(Script self);
  void (*SetEngine)(Script self, ActiveObjectEngine engine);
  void (*SetNotificationComand)(Script self, Command notification_command);
  const char *(*GetName)(Script self);
  int (*GetErrorCode)(Script self);
  bool (*HasError)(Script self);
} ScriptAbstractMethodStruct;
typedef const ScriptAbstractMethodStruct *ScriptAbstractMethod;

extern const ScriptAbstractMethod script;

#endif  // V1_SCRIPT_H_
