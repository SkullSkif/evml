  #include "simplebasic.h"

  void
  postprocessJumps (int i)
  {
    int parsed_values = sscanf (asmString[i], "%d %d %d %s %d", &linenum,
                                &strnum, &asm_addr, opr, &goto_line);
    if (parsed_values != 5)
      {
        printf ("Invalid syntax\n");
        return;
      }

    int goto_addr = sb_getGotoAddr (goto_line);
    if (goto_addr == -1)
      {
        printf ("Invalid syntax\n");
        return;
      }

    sprintf (asmStringOut[i], "%02d %s %02d\n", asm_addr, opr, goto_addr);
  }
