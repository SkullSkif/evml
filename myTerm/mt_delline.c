#include <myTerm.h>
int
mt_delline ()
{
  printf ("\033[K");
  return 0;
}