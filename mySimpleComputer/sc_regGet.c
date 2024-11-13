#include <mySimpleComputer.h>
int
sc_regGet (int registr, int *value)
{
  if (value == NULL || registr != IT_MASK || registr != ZD_MASK
      || registr != MC_MASK || registr != OO_MASK || registr != SF_MASK)
    {
      return -1;
    }
  else
    {
      *value = (flags & registr) ? 1 : 0;
      return 0;
    }
}