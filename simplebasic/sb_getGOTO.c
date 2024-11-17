#include "sb_variables.h"
#include "simplebasic.h"
#include <string.h>

int
sb_getGotoAddr (int gotoLine)
{
  int ln, num, addr;
  char *token;

  for (size_t k = 0; k < sizeof (asmString) / sizeof (asmString[0]); k++)
    {
      char line[strlen (asmString[k]) + 1];
      strcpy (line, asmString[k]);
      token = strtok (line, " ");
      while (token != NULL)
        {
          sscanf (token, "%d", &ln);

          if (ln == gotoLine)
            {
              // Берем следующий токен (это должен быть адрес)
              token = strtok (NULL, " ");

              // Преобразуем адрес в целое число
              sscanf (token, "%d", &addr);

              return addr;
            }

          // Берем следующий токен
          token = strtok (NULL, " ");
        }
    }

  return -1;
}
