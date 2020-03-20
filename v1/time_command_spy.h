// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#ifndef V1_TIME_COMMAND_SPY_H_
#define V1_TIME_COMMAND_SPY_H_

typedef struct {
  void (*Reset)(void);
  int (*Time)(void);
  void (*Execute)(void);
} TimeCommandSpyMethodStruct;
typedef const TimeCommandSpyMethodStruct* TimeCommandSpyMethod;

extern const TimeCommandSpyMethod timeCommandSpy;

#endif  // V1_TIME_COMMAND_SPY_H_
