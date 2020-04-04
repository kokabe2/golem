// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "null_display.h"

#include <stddef.h>

#include "component_private.h"

static ComponentStruct the_singleton;
static Component the_instance = NULL;

static void Delete(Component* self) {}

static int NonsenseValue(Component self) { return ~0; }

static const char* EmptyString(Component self) { return ""; }

static void NoEffect(Component self) {}

static const DisplayInterfaceStruct kTheInterface = {
    .Delete = Delete,
    .Id = NonsenseValue,
    .Tag = EmptyString,
    .Reset = NoEffect,
};

inline static Component New(void) {
  the_singleton.impl = (ComponentInterface)&kTheInterface;
  return &the_singleton;
}

static Component GetInstance(void) {
  if (the_instance == NULL) the_instance = New();
  return the_instance;
}

static const NullDisplayMethodStruct kTheMethod = {
    .GetInstance = GetInstance,
};

const NullDisplayMethod nullDisplay = &kTheMethod;
