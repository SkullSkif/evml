#include "console.h"

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

void
printCell (int address)
{
  int *sign = malloc (sizeof (int));
  int *command = malloc (sizeof (int));
  int *operand = malloc (sizeof (int));
  sc_commandDecode (memory[address], sign, command, operand);
  printf ("sign = %d\n command = %d\n operand = %d\n", *sign, *command,
          *operand);
  return;
}