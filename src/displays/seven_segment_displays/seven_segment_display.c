// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "seven_segment_display.h"

#include "component_private.h"

static void Delete(Component* self) { ((SevenSegmentDisplayInterface)((*self)->impl))->Delete(self); }

static int Id(Component self) { return ((SevenSegmentDisplayInterface)(self->impl))->Id(self); }

static const char* Tag(Component self) { return ((SevenSegmentDisplayInterface)(self->impl))->Tag(self); }

static void Clear(Component self) { ((SevenSegmentDisplayInterface)(self->impl))->Clear(self); }

static uint8_t Get(Component self) { return ((SevenSegmentDisplayInterface)(self->impl))->Get(self); }

static void Set(Component self, uint8_t encoding) { ((SevenSegmentDisplayInterface)(self->impl))->Set(self, encoding); }

static const SevenSegmentDisplayInterfaceStruct kTheInterface = {
    .Delete = Delete,
    .Id = Id,
    .Tag = Tag,
    .Clear = Clear,
    .Get = Get,
    .Set = Set,
};

const SevenSegmentDisplayInterface sevenSegmentDisplay = &kTheInterface;
