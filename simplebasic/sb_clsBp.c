#include "sb_variables.h"
#include "simplebasic.h"

void
sb_clearBackspace (char *str)
{
  int read_index = 0;
  int write_index = 0;

  while (str[read_index] != '\0')
    {
      if (str[read_index] != ' ')
        {
          str[write_index] = str[read_index];
          write_index++;
        }
      read_index++;
    }
  str[write_index] = '\0';
}