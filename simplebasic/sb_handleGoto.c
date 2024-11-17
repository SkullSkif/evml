#include "simplebasic.h"

void
handleGoto ()
{
  int result = sscanf (line, "%d %s %d %s", &strnum, opr, &goto_line, str);
  if (result != 3)
    {
      printf ("Invalid syntax\n");
      return;
    }
  sprintf (asmString[asm_addr], "%d %d %d %s %d%s", linenum, strnum, asm_addr,
           "JUMP", goto_line, "\n");
}