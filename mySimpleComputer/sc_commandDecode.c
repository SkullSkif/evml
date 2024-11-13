#include <mySimpleComputer.h>
int
sc_commandDecode (int value, int *sign, int *command, int *operand)
{
  int temp = value;
  if (temp >> 14 == 1)
    return -1;
  else
    {
      temp = temp >> 14;
      *sign = temp;
      temp = value;
      temp = temp << 1;
      temp = temp >> 8;
      *command = temp;
      temp = value;
      temp = temp & (~(*command << 7));
      *operand = temp;
      return 0;
    }
}