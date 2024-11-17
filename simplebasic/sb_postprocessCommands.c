#include "simplebasic.h"

void
postprocessCommands (int i)
{
  sscanf (asmString[i], "%d %d %d %s %c", &linenum, &strnum, &asm_addr, opr,
          &ch);
  int var_addr = sb_findOrCreateVariableAddress (ch, var_offset);
  sprintf (asmStringOut[i], "%02d %s %02d%s", asm_addr, opr, var_addr, "\n");
  int val;
  if (sscanf (asmString[i], "%*d %*d %*d %s %d", opr, &val) == 2
      && strcmp (opr, "LOAD") == 0)
    {
      numArray[var_addr] = val;
    }
}