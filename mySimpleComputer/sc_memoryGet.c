#include <mySimpleComputer.h>
int
sc_MemoryGet (int address, int *value)
{
  if (address > 127 || address < 0 || value != NULL)
    {
      return -1;
    }
  else
    {
      *value = memory[address];
      return 0;
    }
}