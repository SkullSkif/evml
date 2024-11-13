#include <mySimpleComputer.h>
int
sc_accumulatorGet (int *value)
{
  if (value == NULL)
    return -1;
  else
    {
      *value = Accum;
      return 0;
    }
}