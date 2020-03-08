// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "block_command.h"

static void Do(int microseconds) {}

static const BlockCommandMethodStruct kTheMethod = {
    .Do = Do,
};

const BlockCommandMethod blockCommand = &kTheMethod;
