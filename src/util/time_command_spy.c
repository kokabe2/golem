// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "time_command_spy.h"

#include <stddef.h>

#include "time_command.h"

static TimeCommandActionDelegate its_action;
static int its_time;

static void Reset(void) {
  its_action = NULL;
  its_time = 0;
}

static int Time(void) { return its_time; }

static void Execute(void) { its_action(); }

static const TimeCommandSpyMethodStruct kSpyMethod = {
    .Time = Time, .Execute = Execute,
};

const TimeCommandSpyMethod timeCommandSpy = &kSpyMethod;

static void Do(TimeCommandActionDelegate action, int milliseconds) {
  its_action = action;
  its_time = milliseconds;
}

static const TimeCommandMethodStruct kTheMethod = {
    .Do = Do,
};

const TimeCommandMethod timeCommand = &kTheMethod;
