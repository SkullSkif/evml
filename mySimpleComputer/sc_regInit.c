#include <mySimpleComputer.h>
int
sc_regInit ()
{
  for (int i = 0; i <= 2; i++)
    {
      if (i == 2)
        {
          flags = ~flags & OFF;
        }
      else
        {
          flags = flags & (~OFF);
        }
    }
  return 0;
}