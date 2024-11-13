#include <myBigChars.h>
#include <myReadKey.h>
#include <mySimpleComputer.h>
#include <myTerm.h>
#include <signal.h>

void
IRC (int signum)
{
  if (signum == SIGALRM)
    {
      int flagt;
      static int waitTacts = 0;
      sc_regGet (IT_MASK, &flagt);
      fflush (stdout);
      if (!flagt)
        {
          if (!waitTacts)
            TACTS = 0;
          else if (TACTS < 10)
            TACTS += 1;
          else
            {
              TACTS = 0;
              waitTacts = 0;
            }

          if (!waitTacts)
            CU ();

          drawConsole ();
          alarm (1);
        }
    }
  else if (signum == SIGUSR1)
    {
      sc_accumulatorSet (0);
      sc_icounterSet (0);
    }
}