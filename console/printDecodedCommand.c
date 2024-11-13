#include "console.h"
void
printDecodedCommand (int value)
{
  int Col, Row;
  mt_getscreensize (&Row, &Col);
  mt_gotoXY (1, 15);
  printf ("dec: %05d | oct: %05o | hex: %04X   bin: ", value, value, value);
  for (int q = 0; q <= 14; q++)
    {
      int new_x = 60;
      mt_gotoXY (new_x - q - 1, 15);
      printf ("%d", (value >> q) & 1);
    }
  return;
}