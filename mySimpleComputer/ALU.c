#include <myBigChars.h>
#include <myReadKey.h>
#include <mySimpleComputer.h>
#include <myTerm.h>
#include <signal.h>

int
ALU (int command, int operand)
{
  switch (command)
    {
    case ADD:
      Accum = (Accum + memory[operand]) & 0x7FFF;
      break;

    case SUB:
      Accum = (Accum + ~memory[operand] + 1) & 0x7FFF;
      break;

    case DIVIDE:
      if (memory[operand] != 0)
        Accum /= memory[operand];
      else
        {
          sc_regSet (ZD_MASK, 1);
          return -1;
        }
      break;

    case MUL:
      Accum = (Accum * memory[operand]) & 0x7FFF;
      break;
    }
  if ((Accum > 0x7FFF) || (Accum < 0))
    {
      sc_regSet (OO_MASK, 1);
      return -1;
    }
  else
    sc_regSet (OO_MASK, 0);

  return 0;
}