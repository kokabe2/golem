// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#ifndef V1_WATCH_COMMAND_H_
#define V1_WATCH_COMMAND_H_

#include <stdbool.h>

typedef bool (*WatchCommandObserverDelegate)(void);
typedef struct {
  bool (*Do)(WatchCommandObserverDelegate observer, int delay_in_milliseconds, int period_in_milliseconds,
             int timeout_in_milliseconds);
} WatchCommandMethodStruct;
typedef const WatchCommandMethodStruct* WatchCommandMethod;

extern const WatchCommandMethod watchCommand;

#endif  // V1_WATCH_COMMAND_H_
