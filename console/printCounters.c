#include "console.h"
void
printCounters ()
{
  int Col, Row;
  mt_getscreensize (&Row, &Col);
  mt_gotoXY (62, 5);
  printf ("T: %02d IC: %04X", ICount, ICount);
  bc_box (61, 4, 80, 6, 7, 0, "Счётчик команд", 1, 0);
  return;
}