// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#ifndef V1_ERROR_COMMAND_H_
#define V1_ERROR_COMMAND_H_

#include "active_object_engine.h"
#include "command.h"

typedef void (*NotifyDelegate)(const char* message, int error, int parameter);
typedef struct {
  Command (*New)(NotifyDelegate delegate);
  void (*SetErrorInfo)(Command self, const char* message, int error, int parameter);
} ErrorCommandMethodStruct;
typedef const ErrorCommandMethodStruct* ErrorCommandMethod;

extern const ErrorCommandMethod errorCommand;

#endif  // V1_ERROR_COMMAND_H_
