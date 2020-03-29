// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#ifndef V1_COMMAND_H_
#define V1_COMMAND_H_

typedef struct CommandStruct* Command;
typedef struct {
  void (*Delete)(Command* self);
  void (*Do)(Command self);
} CommandInterfaceStruct;
typedef const CommandInterfaceStruct* CommandInterface;

extern const CommandInterface command;

#endif  // V1_COMMAND_H_
