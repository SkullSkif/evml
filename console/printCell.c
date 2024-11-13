#include "console.h"
void
printCell (int address, enum Colors fg, enum Colors bg)
{
  int x = 2 + 6 * (address % 10);
  int *sign = malloc (sizeof (int));
  int *command = malloc (sizeof (int));
  int *operand = malloc (sizeof (int));
  sc_commandDecode (memory[address], sign, command, operand);
  mt_gotoXY (x, 2 + address / 10);
  mt_setfgcolor (fg);
  mt_setbgcolor (bg);
  if (*sign == 0)
    printf ("+");
  else
    printf ("-");
  printf ("%02d%02d ", *command, *operand);
  mt_setdefaultcolor ();
  return;
}