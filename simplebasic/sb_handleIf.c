#include "simplebasic.h"

void
handleIf ()
{
  char *s = strstr (line, "IF") + 2;
  sb_clearBackspace (s);
  char ch1, ch2, ch3;

  if (sscanf (s, "%c%c%cGOTO%d%s", &ch1, &ch2, &ch3, &goto_line, str) != 4)
    {
      printf ("Invalid syntax\n");
      return;
    }

  sprintf (asmString[asm_addr], "%d %d %d %s %c%s", linenum, strnum, asm_addr,
           "LOAD", ch1, "\n");
  asm_addr++;

  char *jumpInstr = "";
  if ((ch2 == '<' && ch3 == '0') || (ch2 == '>' && ch3 == '0')
      || (ch2 == '=' && ch3 == '0'))
    {
      if (ch2 == '<')
        jumpInstr = "JNEG";
      else if (ch2 == '>')
        jumpInstr = "JNS";
      else if (ch2 == '=')
        jumpInstr = "JZ";

      sprintf (asmString[asm_addr], "%d %d %d %s %d%s", -1, -1, asm_addr,
               jumpInstr, goto_line, "\n");
    }
  else
    {
      printf ("Invalid syntax\n");
      return;
    }
}
