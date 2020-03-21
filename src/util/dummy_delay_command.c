// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "command_protected.h"
#include "delay_command.h"

static void DummyDelete(Command *self) {}

static void DummyDo(Command self) {}

static const CommandAbstractMethodStruct kConcreteMethod = {
    .Delete = DummyDelete,
    .Do = DummyDo,
    .Undo = DummyDo,
    .Redo = DummyDo,
};

static const CommandStruct kDummyInstance = {
    .impl = (CommandAbstractMethod)&kConcreteMethod,
};

static Command New(int milliseconds) { return &kDummyInstance; }

static int DummyGetDelayTime(Command self) { return 0; }

static void DummySetDelayTime(Command self, int milliseconds) {}

static const DelayCommandMethodStruct kTheMethod = {
    .New = New,
    .GetDelayTime = DummyGetDelayTime,
    .SetDelayTime = DummySetDelayTime,
};

const DelayCommandMethod delayCommand = &kTheMethod;
