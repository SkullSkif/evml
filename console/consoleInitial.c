#include "console.h"
int
consoleInitial (int argv, char *argc[])
{
  generateFont ();
  if (!isatty (STDOUT_FILENO))
    {
      printf ("Error: Output is not a terminal\n");
      return 1;
    }
  int rows, cols;
  mt_getscreensize (&rows, &cols);
  if (rows < 26 || cols < 114)
    {
      printf ("Error: Terminal window is too small\n");
      return 1;
    }
  // Открываем файл для чтения
  FILE *file = fopen (argv > 1 ? argc[1] : "font.bin", "rb");
  if (file == NULL)
    {
      printf ("Ошибка шрифт не найден\n");
      return 1;
    }
  int read_result;
  bc_bigcharread (fileno (file), (int *)font, 18, &read_result);
  fclose (file);
  if (read_result == 18 - 1)
    {
      printf ("Ошибка при чтении шрифта из файла\n");
      return 1;
    }
  return 0;
}