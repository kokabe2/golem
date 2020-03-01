// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#ifndef V1_DELAY_COMMAND_H_
#define V1_DELAY_COMMAND_H_

typedef struct {
  void (*Do)(int milliseconds);  //
} DelayCommandMethodStruct;
typedef const DelayCommandMethodStruct* DelayCommandMethod;

extern const DelayCommandMethod delayCommand;

#endif  // V1_DELAY_COMMAND_H_
