#include <mySimpleComputer.h>
int
sc_MemorySet (int address, int value)
{
  if ((address < 0 || address > 127) || (value > 0x7F7F || value < 0))
    {
      return -1;
    }
  else
    {
      memory[address] = value;
      return 0;
    }
}