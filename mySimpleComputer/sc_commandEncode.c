#include <mySimpleComputer.h>
int
sc_commandEncode (int sign, int command, int operand, int *value)
{
  static int commands[40]
      = { 0x00, 0x01, 0x0A, 0x0B, 0x14, 0x15, 0x1E, 0x1F, 0x20, 0x21,
          0x28, 0x29, 0x2A, 0x2B, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38,
          0x39, 0x3A, 0x3B, 0x3C, 0x3D, 0x3E, 0x3F, 0x40, 0x41, 0x42,
          0x43, 0x44, 0x45, 0x46, 0x47, 0x48, 0x49, 0x4A, 0x4B, 0x4C };
  int temp = 0;
  for (int i = 0; i <= 40; i++)
    {
      if (command == commands[i])
        temp = 1;
    }
  if (temp == 0)
    return -1;
  if (sign >= 1 || sign < 0 || operand > 127 || operand < 0)
    return -1;
  else
    {
      int new_comm = 0;
      new_comm = new_comm | command;
      new_comm = new_comm << 7;
      new_comm = new_comm | operand;
      *value = new_comm;
      return 0;
    }
}
