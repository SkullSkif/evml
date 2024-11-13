#include "console.h"
void
printCounters ()
{
  int Col, Row;
  mt_getscreensize (&Row, &Col);
  mt_gotoXY (63, 5);
  printf ("T: %02d        IC: %04X", ICount, ICount);
  bc_box (62, 4, 86, 6, 7, 0, "Счётчик команд", 1, 0);
  return;
}