#include <myBigChars.h>
#include <myReadKey.h>
#include <mySimpleComputer.h>
#include <myTerm.h>
#include <signal.h>

void
CU ()
{
  int operand, read, sign, command;
  if (sc_commandDecode (memory[ICount], &sign, &command, &operand) != 0)
    {
      sc_regSet (MC_MASK, 1);
      sc_regSet (IT_MASK, 1);
      return;
    }
  if ((operand < 0) && (operand >= 128))
    {
      sc_regSet (MC_MASK, 1);
      sc_regSet (IT_MASK, 1);
      return;
    }
  if (command == ADD || command == SUB || command == DIVIDE || command == MUL)
    {
      if (ALU (command, operand) != 0)
        sc_regSet (IT_MASK, 1);
    }
  else
    {
      switch (command)
        {
        case READ:
          mt_gotoXY (75, 20);
          printf ("      ");
          printTerm (operand, 0);
          rk_mytermrestore ();
          mt_gotoXY (75, 20);
          if (rk_readvalue (&read, 0))
            read = 0;
          rk_mytermregime (0, 30, 0, 0, 0);

          printTerm (operand, read);

          if (sc_MemorySet (operand, read) != 0)
            {
              sc_regSet (IT_MASK, 0);
              break;
            }
          sc_regSet (IT_MASK, 0);
          break;

        case WRITE:
          printTerm (operand, -1);
          break;

        case LOAD:
          sc_accumulatorSet (memory[operand]);
          break;

        case STORE:
          sc_MemorySet (operand, Accum);
          break;

        case JUMP:
          sc_icounterSet (operand - 1);
          break;

        case JNEG:
          if ((Accum >> 14) & 1 && Accum != 0)
            sc_icounterSet (operand - 1);
          break;

        case JZ:
          if (Accum == 0)
            sc_icounterSet (operand - 1);
          break;

        case HALT:
          sc_regSet (IT_MASK, 1);
          break;

        default:
          sc_regSet (IT_MASK, 1);
          break;
        }
    }
  ICount++;
}