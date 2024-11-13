#include <mySimpleComputer.h>
int
sc_MemoryInit ()
{
  for (int i = 0; i <= 127; i++)
    {
      memory[i] = 0;
    }
  return 0;
}