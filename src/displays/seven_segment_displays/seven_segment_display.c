// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "seven_segment_display.h"

#include "seven_segment_display_private.h"

static void Delete(SevenSegmentDisplay* self) { (*self)->impl->Delete(self); }

static int Id(SevenSegmentDisplay self) { return self->impl->Id(self); }

static const char* Tag(SevenSegmentDisplay self) { return self->impl->Tag(self); }

static void Clear(SevenSegmentDisplay self) { self->impl->Clear(self); }

static uint8_t Get(SevenSegmentDisplay self) { return self->impl->Get(self); }

static void Set(SevenSegmentDisplay self, uint8_t encoding) { self->impl->Set(self, encoding); }

static const SevenSegmentDisplayInterfaceStruct kTheInterface = {
    .Delete = Delete,
    .Id = Id,
    .Tag = Tag,
    .Clear = Clear,
    .Get = Get,
    .Set = Set,
};

const SevenSegmentDisplayInterface sevenSegmentDisplay = &kTheInterface;
