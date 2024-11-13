#include <mySimpleComputer.h>
int
sc_icounterSet (int value)
{
  if (value > 127 || value < 0)
    return -1;
  else
    {
      ICount = value;
      return 0;
    }
}