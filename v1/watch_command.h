// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#ifndef V1_WATCH_COMMAND_H_
#define V1_WATCH_COMMAND_H_

#include <stdbool.h>

#include "active_object_engine.h"

typedef bool (*WatchCommandObserverDelegate)(void);
typedef struct {
  Command (*New)(WatchCommandObserverDelegate observer, ActiveObjectEngine engine, Command notification_command);
  void (*SetTimeout)(Command self, int milliseconds, Command timeout_command);
} WatchCommandMethodStruct;
typedef const WatchCommandMethodStruct* WatchCommandMethod;

extern const WatchCommandMethod watchCommand;

#endif  // V1_WATCH_COMMAND_H_
