#include "console.h"
int
main ()
{
  int rows, cols;
  mt_getscreensize (&rows, &cols);
  if (cols < 90 || rows < 26)
    return -1;
  generateFont ();
  FILE *file = fopen ("font.bin", "rb");
  int read_result;
  bc_bigcharread (fileno (file), (int *)font, 18, &read_result);
  setlocale (LC_ALL, ".UTF-8");
  fclose (file);
  sc_MemoryInit ();
  mt_clrscrn ();
  printMemory ();
  printAccumulator ();
  printCounters ();
  printFlags ();
  printDecodedCommand (memory[0]);
  printCommand ();
  printBigCell (memory[1], 67, 9);
  printKeys ();
  for (int t = 0; t < 7; t++)
    {
      int new_adr = rand () % 10;
      printTerm (new_adr, 1);
    }
  mt_clrscrn ();
  printMemory ();
  printAccumulator ();
  printCounters ();
  printFlags ();
  printDecodedCommand (memory[0]);
  printCommand ();
  printTerm (0, 0);
  printBigCell (memory[1], 67, 9);
  printKeys ();
  return 0;
}