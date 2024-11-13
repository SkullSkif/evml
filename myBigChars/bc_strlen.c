#include <myBigChars.h>
int
bc_strlen (char *str)
{
  int length = 0;
  for (; *str++ != '\0'; length++, str++)
    {
      if ((*str & 0xc0) == 0x80 || str == NULL)
        return -1;
    }
  return length;
}