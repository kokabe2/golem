// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "script.h"

#include "script_protected.h"

static void Delete(Script* self) { (*self)->impl.Delete((Command*)self); }

static void Run(Script self) { self->impl.Do((Command)self); }

static void SetEngine(Script self, ActiveObjectEngine engine) { self->engine = engine; }

static void SetNotificationComand(Script self, Command notification_command) {
  self->notification_command = notification_command;
}

static const char* GetName(Script self) { return self->name; }

static int GetErrorCode(Script self) { return self->error_code; }

static bool HasError(Script self) { return self->error_code != 0; }

static const ScriptAbstractMethodStruct kTheMethod = {
    .Delete = Delete,
    .Run = Run,
    .SetEngine = SetEngine,
    .SetNotificationComand = SetNotificationComand,
    .GetName = GetName,
    .GetErrorCode = GetErrorCode,
    .HasError = HasError,
};

const ScriptAbstractMethod script = &kTheMethod;
