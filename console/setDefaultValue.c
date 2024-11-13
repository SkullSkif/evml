#include "console.h"
int
setDefaultValue ()
{
  for (int i = 0; i < 128; i++)
    sc_MemorySet (i, 0);

  sc_accumulatorSet (0);
  sc_icounterSet (0);
  sc_regSet (OO_MASK, 0);
  sc_regSet (MC_MASK, 0);
  sc_regSet (SF_MASK, 0);
  sc_regSet (ZD_MASK, 0);
  sc_regSet (IT_MASK, 1);

  return 0;
}