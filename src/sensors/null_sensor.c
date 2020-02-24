// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "null_sensor.h"

static int Id(void) { return ~0; }
static const char* Tag(void) { return ""; }
static const char* State(void) { return ""; }
static bool IsDefaultState(void) { return false; }
static const SensorInterfaceStruct kTheMethod = {
    .Id = Id, .Tag = Tag, .State = State, .IsDefaultState = IsDefaultState,
};
const SensorInterface nullSensor = &kTheMethod;
