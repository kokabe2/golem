// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "watch_command.h"

#include "malkt/v1/task.h"

inline static bool Validate(int period_in_milliseconds, int timeout_in_milliseconds) {
  return (period_in_milliseconds > 0 && timeout_in_milliseconds > 0) || timeout_in_milliseconds == 0;
}

inline static void DelayBeforeWatch(int delay_in_milliseconds) { task->Delay(delay_in_milliseconds); }

static bool Watch(WatchDelegate watch, int period_in_milliseconds, int timeout_in_milliseconds) {
  for (int i = 0; i < timeout_in_milliseconds; task->Delay(period_in_milliseconds), i += period_in_milliseconds)
    if (watch()) return true;
  return watch();
}

static bool Do(WatchDelegate watch, int delay_in_milliseconds, int period_in_milliseconds,
               int timeout_in_milliseconds) {
  if (!Validate(period_in_milliseconds, timeout_in_milliseconds)) return false;
  DelayBeforeWatch(delay_in_milliseconds);
  return Watch(watch, period_in_milliseconds, timeout_in_milliseconds);
}

static const WatchCommandMethodStruct kTheMethod = {
    .Do = Do,
};

const WatchCommandMethod watchCommand = &kTheMethod;
