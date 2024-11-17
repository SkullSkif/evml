#include "simplebasic.h"

typedef struct
{
  const char *name;
  int code;
} Command;

int
sa_commandValidate (char *command)
{
  Command commands[]
      = { { "NOP", 0x00 },   { "CPUINFO", 0x01 }, { "READ", 0x0A },
          { "WRITE", 0x0B }, { "LOAD", 0x14 },    { "STORE", 0x15 },
          { "ADD", 0x1E },   { "SUB", 0x1F },     { "DIVIDE", 0x20 },
          { "MUL", 0x21 },   { "JUMP", 0x28 },    { "JNEG", 0x29 },
          { "JZ", 0x2A },    { "HALT", 0x2B },    { "JNS", 0x37 },
          { "JP", 0x3A },    { "SUBC", 0x42 } };
  int numCommands = sizeof (commands) / sizeof (commands[0]);

  for (int i = 0; i < numCommands; ++i)
    {
      if (strcmp (command, commands[i].name) == 0)
        {
          return commands[i].code;
        }
    }

  if (command[0] == '=')
    {
      return 1;
    }

  return -1;
}