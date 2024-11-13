#include "console.h"
void
printCommand ()
{
  int Col, Row;
  int *sign = malloc (sizeof (int));
  int *command = malloc (sizeof (int));
  int *operand = malloc (sizeof (int));
  mt_getscreensize (&Row, &Col);
  mt_gotoXY (82, 5);
  if (sc_commandDecode (memory[ICount], sign, command, operand) == -1)
    {
      printf ("!");
      return;
    }
  if (*sign == 0)
    printf ("+");
  else
    printf ("-");
  printf ("%02d : %02d", *command, *operand);
  return;
}