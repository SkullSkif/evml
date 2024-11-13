#include <myTerm.h>
int
mt_set_cursorvisible (int value)
{
  if (value == 1)
    {
      printf ("\033[?25h");
      return 0;
    }
  else if (value == 0)
    {
      printf ("\033[?25l");
      return 0;
    }
  else
    return -1;
}