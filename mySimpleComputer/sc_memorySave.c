#include <mySimpleComputer.h>
int
sc_MemorySave (char *filename)
{
  FILE *fp = fopen (filename, "r+");
  if (!fp)
    return -1;
  else
    {
      fwrite (&memory[0], sizeof (int), 127, fp);
      return 0;
    }
}