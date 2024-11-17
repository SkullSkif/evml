#include "simplebasic.h"

void
handleEnd ()
{
  int result = sscanf (line, "%d %s %s", &strnum, opr, str);
  if (result != 2)
    {
      printf ("Invalid syntax\n");
      return;
    }
  sprintf (asmString[asm_addr], "%d %d %d %s", linenum, strnum, asm_addr,
           "HALT\n");
}