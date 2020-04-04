// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "active_object_engine.h"

static void Delete(ActiveObjectEngine* self) { (*self)->Delete(self); }

static void Run(ActiveObjectEngine self) { self->Run(self); }

static void AddCommand(ActiveObjectEngine self, Command c) { self->AddCommand(self, c); }

static const ActiveObjectEngineInterfaceStruct kTheInterface = {
    .Delete = Delete,
    .Run = Run,
    .AddCommand = AddCommand,
};

const ActiveObjectEngineInterface activeObjectEngine = &kTheInterface;
