// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "active_object_engine.h"

#include "active_object_engine_private.h"

static void Delete(ActiveObjectEngine* self) { (*self)->impl->Delete(self); }

static void Run(ActiveObjectEngine self) { self->impl->Run(self); }

static void AddCommand(ActiveObjectEngine self, Command c) { self->impl->AddCommand(self, c); }

static const ActiveObjectEngineInterfaceStruct kTheInterface = {
    .Delete = Delete, .Run = Run, .AddCommand = AddCommand,
};

const ActiveObjectEngineInterface activeObjectEngine = &kTheInterface;
