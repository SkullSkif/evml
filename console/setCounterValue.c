#include "console.h"
int
setCounterValue ()
{
  mt_gotoXY (62 + 12, 5);
  int number;
  rk_readvalue (&number, 0);
  sc_icounterSet (number);
  return 0;
}