// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "block_command.h"
#include "command_protected.h"

static void DummyDelete(Command *self) {}

static void Dummy(Command self) {}

static const CommandAbstractMethodStruct kConcreteMethod = {
    .Delete = DummyDelete,
    .Do = Dummy,
};

static const CommandStruct kDummyInstance = {
    .impl = (CommandAbstractMethod)&kConcreteMethod,
};

static Command New(int microseconds) { return &kDummyInstance; }

static const BlockCommandMethodStruct kTheMethod = {
    .New = New,
};

const BlockCommandMethod blockCommand = &kTheMethod;
