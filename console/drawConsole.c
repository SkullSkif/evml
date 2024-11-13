#include "console.h"
#include <locale.h>
void
drawConsole ()
{
  mt_clrscrn ();
  printMemory ();
  printAccumulator ();
  printCounters ();
  printFlags ();
  printDecodedCommand (memory[ICount]);
  printCommand ();
  FILE *file = fopen ("font.bin", "rb");
  int read_result;
  bc_bigcharread (fileno (file), (int *)font, 18, &read_result);
  fclose (file);
  bc_box (62, 7, 114, 18, 7, 0, "Редактируемая ячейка (увеличенно)", 1, 0);
  printBigCell (memory[ICount], 67, 9);
  printKeys ();
  printTerm (0, 0);
  mt_gotoXY (0, 26);
}