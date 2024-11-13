#include <myTerm.h>
int
mt_setfgcolor (enum Colors color)
{
  printf ("\033[38;5;%dm", color);
  return 0;
}