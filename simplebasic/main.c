#include "mySimpleComputer.h"
#include "sb_variables.h"
#include "sc.h"
#include "simplebasic.h"

int
main (int argc, char **argv)
{
  FILE *file_sb, *file_sa;

  if (argc != 3)
    {
      fprintf (stderr, "Usage: %s file.sb file.sa\n", argv[0]);
      return -1;
    }

  if ((file_sb = fopen (argv[1], "rb")) == NULL)
    {
      fprintf (stderr, "Error: Unable to open '%s' file for reading.\n",
               argv[1]);
      return -1;
    }

  if ((file_sa = fopen (argv[2], "wb")) == NULL)
    {
      fprintf (stderr, "Error: Unable to create '%s' file for writing.\n",
               argv[2]);
      fclose (file_sb);
      return -1;
    }

  fprintf (stdout, "Basic file '%s' is successfully opened.\n", argv[1]);

  compileBasic (file_sb, file_sa, argv, 1);

  fclose (file_sb);
  fclose (file_sa);
  return 0;
}