#include "console.h"
void
printCounters ()
{
  int Col, Row;
  mt_getscreensize (&Row, &Col);
  mt_gotoXY (62, 5);
  printf ("T: %02d IC: %04X", ICount, ICount);
  return;
}