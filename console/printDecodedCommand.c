#include "console.h"
void
printDecodedCommand (int value)
{
  int Col, Row;
  mt_getscreensize (&Row, &Col);
  bc_box (1, 16, 60, 18, 7, 0, "Редактируемая Ячейка", 1, 0);
  mt_gotoXY (2, 17);
  printf ("dec: %05d | oct: %05o | hex: %04X   bin: ", value, value, value);
  for (int q = 0; q <= 14; q++)
    {
      int new_x = 60;
      mt_gotoXY (new_x - q - 1, 17);
      printf ("%d", (value >> q) & 1);
    }
  return;
}