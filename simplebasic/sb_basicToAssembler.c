#include "simplebasic.h"

int var_offset, strnum, asm_addr = 0, last_strnum = 0;
int max_strnum, goto_addr, goto_line;
char opr[6], str[100], ch;
char line[100];
int linenum = 1;

void
initializeVariables ()
{
  for (size_t i = 0; i < sizeof (asmString) / sizeof (asmString[0]); i++)
    {
      sprintf (asmString[i], "%s", "");
    }

  for (size_t i = 0; i < sizeof (asmStringOut) / sizeof (asmStringOut[0]); i++)
    {
      sprintf (asmStringOut[i], "%s", "");
    }

  for (size_t i = 0; i < sizeof (variables); i++)
    {
      strcpy (&variables[i], "\0");
    }
}

int
dispatchInstruction (int strnum, char *opr)
{
  if (strcmp (opr, "REM") == 0)
    {
      linenum++;
      return 0;
    }
  else if (strcmp (opr, "END") == 0)
    {
      handleEnd ();
    }
  else if (strcmp (opr, "INPUT") == 0)
    {
      handleInput ();
    }
  else if (strcmp (opr, "LET") == 0)
    {
      handleLet ();
    }
  else if (strcmp (opr, "IF") == 0)
    {
      handleIf ();
    }
  else if (strcmp (opr, "GOTO") == 0)
    {
      handleGoto ();
    }
  else if (strcmp (opr, "PRINT") == 0)
    {
      handlePrint ();
    }
  else
    {
      printf ("Invalid syntax\n");
      return -1;
    }
}

void
postprocess (int i)
{
  sscanf (asmString[i], "%d %d %d %s", &linenum, &strnum, &asm_addr, opr);
  if ((strcmp (opr, "READ") == 0) || (strcmp (opr, "WRITE") == 0)
      || (strcmp (opr, "LOAD") == 0) || (strcmp (opr, "STORE") == 0)
      || (strcmp (opr, "ADD") == 0) || (strcmp (opr, "SUB") == 0)
      || (strcmp (opr, "DIVIDE") == 0) || (strcmp (opr, "MUL") == 0))
    {
      postprocessCommands (i);
    }
  else if ((strcmp (opr, "JUMP") == 0) || (strcmp (opr, "JNEG") == 0)
           || (strcmp (opr, "JNS") == 0) || (strcmp (opr, "JZ") == 0))
    {
      postprocessJumps (i);
    }
  else if (strcmp (opr, "HALT") == 0)
    {
      postprocessHalt (i);
    }
}

int
processLineFromFile (FILE *file_sb)
{
  fgets (line, sizeof (line), file_sb);
  if (feof (file_sb))
    {
      return 0;
    }

  printf ("%s", line);
  if (strcmp (line, "\n") != 0)
    {
      if (sscanf (line, "%d %s", &strnum, opr) >= 2)
        {
          if (strnum <= last_strnum)
            {
              printf ("Invalid syntax\n");
              return -1;
            }
          dispatchInstruction (strnum, opr);
          asm_addr++;
          last_strnum = strnum;
        }
      else
        {
          printf ("Invalid syntax\n");
          return -1;
        }
    }
}

int
compileBasic (FILE *file_sb, FILE *file_sa, char **argv, int flag)
{
  initializeVariables ();

  // Цикл обработки строк файла
  do
    {
      processLineFromFile (file_sb);
      linenum++;
    }
  while (!feof (file_sb));

  fclose (file_sb);
  max_strnum = strnum;
  var_offset = asm_addr;

  // Постобработка инструкций и переменных
  for (int i = 0; i < sizeof (asmString) / sizeof (asmString[0]); i++)
    {
      if (strcmp (asmString[i], "") != 0)
        {
          postprocess (i);
        }
      else
        {
          if (i >= var_offset)
            {
              postprocessVariables (i);
            }
        }
    }

  // Запись результата в файл
  for (int i = 0; i < sizeof (asmString) / sizeof (asmString[0]); i++)
    {
      fwrite (asmStringOut[i], 1, strlen (asmStringOut[i]), file_sa);
    }

  fclose (file_sa);

  if (flag == 1)
    {
      exit (0);
    }

  if ((file_sa = fopen (argv[2], "r")) == NULL)
    {
      printf ("Unable to open file '%s'\n", argv[2]);
      return -1;
    }

  if (fseek (file_sa, 0, SEEK_SET) != 0)
    {
      printf ("Error moving file pointer\n");
      return -1;
    }

  return 0;
}
