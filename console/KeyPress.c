#include "console.h"
#include <signal.h>
void
handleKeypress (enum keys *key)
{
  switch (*key)
    {
    case KEY_R:
      sc_regSet (IT_MASK, 0);
      interact_mode = 1;
      break;
    case KEY_T:
      if (ICount >= 127)
        ICount = 0;
      else if (interact_mode)
        CU ();
      break;
    case KEY_I:
      raise (SIGUSR1);
      interact_mode = 0;
      break;
    }

  if (interact_mode)
    return;

  switch (*key)
    {
    case KEY_UP:
      (ICount <= 9) ? (ICount += (ICount >= 8 ? 110 : 120)) : (ICount -= 10);
      break;
    case KEY_RIGHT:
      (!((ICount + 1) % (ICount >= 120 ? 8 : 10)))
          ? (ICount -= (ICount >= 120 ? 7 : 9))
          : (ICount += 1);
      break;
    case KEY_DOWN:
      (ICount >= 118) ? (ICount -= (ICount < 120 ? 110 : 120))
                      : (ICount += 10);
      break;
    case KEY_LEFT:
      (!(ICount % 10)) ? (ICount += (ICount >= 120 ? 7 : 9)) : (ICount -= 1);
      break;

    case KEY_L:
      loadMemory ();
      break;
    case KEY_S:
      saveMemory ();
      break;

    case KEY_F5:
      setAccumulatorValue ();
      break;
    case KEY_F6:
      setCounterValue ();
      break;

    case KEY_ENTER:
      setCellValue ();
      break;

    case KEY_OTHER:
      break;

    case KEY_ESC:
      break;
    }
}