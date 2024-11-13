#include "console.h"
void
printMemory ()
{
  for (int f = 0; f < 128; f++)
    {
      printCell (f, 0, 0);
    }
  bc_box (1, 1, 60, 13, 7, 0, "Оперативная память", 1, 0);
}