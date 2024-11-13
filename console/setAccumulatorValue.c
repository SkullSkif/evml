#include "console.h"
int
setAccumulatorValue ()
{
  mt_gotoXY (67, 2);
  int number;
  rk_readvalue (&number, 0);
  sc_accumulatorSet (number);
  return 0;
}