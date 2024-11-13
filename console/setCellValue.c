#include "console.h"
int
setCellValue ()
{
  mt_gotoXY (ICount % 10 * 6 + 2 + 2, ICount / 10 + 2);
  int number;
  rk_readvalue (&number, 0);
  sc_MemorySet (ICount, number);
  return 0;
}