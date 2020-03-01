// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "null_sensor.h"

static int NonsenseValue(void) { return ~0; }

static const char* EmptyString(void) { return ""; }

static bool False(void) { return false; }

static const SensorInterfaceStruct kTheMethod = {
    .Id = NonsenseValue, .Tag = EmptyString, .State = EmptyString, .IsDefaultState = False,
};

const SensorInterface nullSensor = &kTheMethod;
