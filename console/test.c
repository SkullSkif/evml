#include "console.h"

int
main ()
{
  int rows, cols;
  mt_getscreensize (&rows, &cols);
  if (cols < 92 || rows < 23)
    return -1;
  sc_MemoryInit ();
  for (int f = 0; f < 128; f++)
    {
      printCell (f, 0, 0);
    }
  printAccumulator ();
  printCounters ();
  printFlags ();
  printDecodedCommand (memory[0]);
  printCommand ();
  printTerm (2, 0);
  return 0;
}