// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#ifndef V1_TIME_COMMAND_H_
#define V1_TIME_COMMAND_H_

typedef void (*TimeCommandActionDelegate)(void);
typedef struct {
  void (*Do)(TimeCommandActionDelegate action, int milliseconds);  //
} TimeCommandMethodStruct;
typedef const TimeCommandMethodStruct* TimeCommandMethod;

extern const TimeCommandMethod timeCommand;

#endif  // V1_TIME_COMMAND_H_
