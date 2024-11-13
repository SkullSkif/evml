#include "console.h"
void
printMemory ()
{
  enum Colors fg = GREEN, bg = BLACK;
  for (int i = 0; i < 128; i++)
    {
      if (i == ICount)
        {
          fg = BLACK;
          bg = WHITE;
        }
      else
        {
          fg = GREEN;
          bg = BLACK;
        }
      printCell (i, fg, bg);
    }
  bc_box (1, 1, 61, 15, 7, 0, "Оперативная память", 1, 0);
}