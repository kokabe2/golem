// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "seven_segment_display.h"

static void Delete(Component* self) { ((SevenSegmentDisplayInterface)(*self))->Delete(self); }

static int Id(Component self) { return ((SevenSegmentDisplayInterface)self)->Id(self); }

static const char* Tag(Component self) { return ((SevenSegmentDisplayInterface)self)->Tag(self); }

static void Clear(Component self) { ((SevenSegmentDisplayInterface)self)->Clear(self); }

static uint8_t Get(Component self) { return ((SevenSegmentDisplayInterface)self)->Get(self); }

static void Set(Component self, uint8_t encoding) { ((SevenSegmentDisplayInterface)self)->Set(self, encoding); }

static const SevenSegmentDisplayInterfaceStruct kTheInterface = {
    .Delete = Delete,
    .Id = Id,
    .Tag = Tag,
    .Clear = Clear,
    .Get = Get,
    .Set = Set,
};

const SevenSegmentDisplayInterface sevenSegmentDisplay = &kTheInterface;
