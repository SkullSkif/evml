#include <myTerm.h>
int
mt_setbgcolor (enum Colors color)
{
  printf ("\033[48;5;%dm", color);
  return 0;
}