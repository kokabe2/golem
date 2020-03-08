// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "watch_command.h"

static bool Do(WatchDelegate watch, int delay_in_milliseconds, int period_in_milliseconds,
               int timeout_in_milliseconds) {
  return true;
}

static const WatchCommandMethodStruct kTheMethod = {
    .Do = Do,
};

const WatchCommandMethod watchCommand = &kTheMethod;
