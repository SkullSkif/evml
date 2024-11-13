#include <myTerm.h>
int
mt_clrscrn ()
{
  printf ("\033[H\033[2J");
  return 0;
}