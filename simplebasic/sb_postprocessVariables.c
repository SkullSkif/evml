#include "simplebasic.h"

void
postprocessVariables (int i)
{
  char varName = sb_getVariableName (i, var_offset);
  if (varName != '\0')
    {
      sprintf (asmStringOut[i], "%02d %c %s", i, '=', "+0000\n");
    }
  if (numArray[i] != 0)
    {
      sprintf (asmStringOut[i], "%02d %c +%04X%s", i, '=', numArray[i], "\n");
    }
}