// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "watch_command.h"

#include "malkt/v1/task.h"

inline static void DelayBeforeWatch(int delay_in_milliseconds) { task->Delay(delay_in_milliseconds); }

static bool Watch(WatchCommandObserverDelegate observer, int period_in_milliseconds, int timeout_in_milliseconds) {
  for (int i = 0; i < timeout_in_milliseconds; task->Delay(period_in_milliseconds), i += period_in_milliseconds)
    if (observer()) return true;
  return observer();
}

static bool Do(WatchCommandObserverDelegate observer, int delay_in_milliseconds, int period_in_milliseconds,
               int timeout_in_milliseconds) {
  DelayBeforeWatch(delay_in_milliseconds);
  return Watch(observer, period_in_milliseconds, timeout_in_milliseconds);
}

static const WatchCommandMethodStruct kTheMethod = {
    .Do = Do,
};

const WatchCommandMethod watchCommand = &kTheMethod;
