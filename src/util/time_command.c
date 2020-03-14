// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "time_command.h"

#include "one_shot_timer_manager.h"

static void Do(TimeCommandActionDelegate action, int milliseconds) { oneShotTimerManager->Add(action, milliseconds); }

static const TimeCommandMethodStruct kTheMethod = {
    .Do = Do,
};

const TimeCommandMethod timeCommand = &kTheMethod;
