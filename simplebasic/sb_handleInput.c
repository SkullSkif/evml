#include "simplebasic.h"

void
handleInput ()
{
  int result = sscanf (line, "%d %s %c %s", &strnum, opr, &ch, str);

  if (result != 3)
    {
      printf ("Invalid syntax\n");
      return;
    }

  sprintf (asmString[asm_addr], "%d %d %d %s %c%s", linenum, strnum, asm_addr,
           "READ", ch, "\n");
}
