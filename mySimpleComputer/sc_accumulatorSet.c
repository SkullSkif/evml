#include <mySimpleComputer.h>
int
sc_accumulatorSet (int value)
{
  if (value > 128 || value < -128)
    return -1;
  else
    {
      Accum = value;
      return 0;
    }
}