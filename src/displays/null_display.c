// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "null_display.h"

#include <stddef.h>

#include "display_private.h"

static DisplayStruct the_singleton;
static Display the_instance = NULL;

static void Delete(Display* self) {}

static int NonsenseValue(Display self) { return ~0; }

static const char* EmptyString(Display self) { return ""; }

static void NoEffect(Display self) {}

static const DisplayInterfaceStruct kTheInterface = {
    .Delete = Delete,
    .Id = NonsenseValue,
    .Tag = EmptyString,
    .Reset = NoEffect,
};

inline static Display New(void) {
  the_singleton.impl = &kTheInterface;
  return &the_singleton;
}

static Display GetInstance(void) {
  if (the_instance == NULL) the_instance = New();
  return the_instance;
}

static const NullDisplayMethodStruct kTheMethod = {
    .GetInstance = GetInstance,
};

const NullDisplayMethod nullDisplay = &kTheMethod;
