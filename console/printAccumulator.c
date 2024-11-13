#include "console.h"
void
printAccumulator ()
{
  int Col, Row;
  mt_getscreensize (&Row, &Col);
  mt_gotoXY (63, 2);
  int *sign = malloc (sizeof (int));
  int *command = malloc (sizeof (int));
  int *operand = malloc (sizeof (int));
  sc_commandDecode (Accum, sign, command, operand);
  printf ("sc: ");
  if (*sign == 1)
    printf ("+");
  else
    printf ("-");
  printf ("%02d%02d    ", *command, *operand);
  printf (" hex:%04X ", Accum);
  bc_box (62, 1, 86, 3, 7, 0, "Аккумулятор", 1, 0);
  return;
}