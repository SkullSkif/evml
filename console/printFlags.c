#include "console.h"
void
printFlags ()
{
  printf ("Flag 0 is: %s \n", (flags & IT_MASK) == IT_MASK ? "I" : "_");
  printf ("Flag 1 is: %s \n", (flags & MC_MASK) == MC_MASK ? "M" : "_");
  printf ("Flag 2 is: %s \n", (flags & SF_MASK) == SF_MASK ? "S" : "_");
  printf ("Flag 3 is: %s \n", (flags & ZD_MASK) == ZD_MASK ? "Z" : "_");
  printf ("Flag 4 is: %s \n", (flags & OO_MASK) == OO_MASK ? "O" : "_");
  return;
}