#include "simplebasic.h"

void
postprocessHalt (int i)
{
  sscanf (asmString[i], "%d %d %d %s", &linenum, &strnum, &asm_addr, opr);
  sprintf (asmStringOut[i], "%02d %s%s", asm_addr, opr, " 00\n");
}