﻿// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "delay_command.h"

#include "malkt/v1/task.h"

static void Do(int time_in_milliseconds) { task->Delay(time_in_milliseconds); }
static const DelayCommandMethodStruct kTheMethod = {
    .Do = Do,
};
const DelayCommandMethod delayCommand = &kTheMethod;