// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "null_temperature_sensor.h"

static int Id(void) { return ~0; }
static const char* Tag(void) { return ""; }
static const char* State(void) { return ""; }
static bool IsNormal(void) { return false; }
static const TemperatureSensorInterfaceStruct kTheMethod = {
    .Id = Id, .Tag = Tag, .State = State, .IsNormal = IsNormal,
};
const TemperatureSensorInterface nullTemperatureSensor = &kTheMethod;
