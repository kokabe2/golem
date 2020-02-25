// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#ifndef V1_DC_MOTOR_INTERFACE_H_
#define V1_DC_MOTOR_INTERFACE_H_

#include <stdbool.h>

typedef struct {
  int (*Id)(void);
  const char* (*Tag)(void);
  const char* (*State)(void);
  void (*Run)(void);
  void (*Stop)(void);
  bool (*IsRunning)(void);
  void (*ForceStop)(void);
  void (*SetToCw)(void);
  void (*SetToAcw)(void);
  bool (*IsCw)(void);
  int (*GetSpeed)(void);
  void (*SetSpeed)(int speed_in_rpm);
} DcMotorInterfaceStruct;
typedef const DcMotorInterfaceStruct* DcMotorInterface;

#endif  // V1_DC_MOTOR_INTERFACE_H_
