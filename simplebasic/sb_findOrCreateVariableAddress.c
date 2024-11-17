#include "sb_variables.h"
#include "simplebasic.h"

int
sb_findOrCreateVariableAddress (char varName, int startOffset)
{
  size_t i;
  for (i = 0; i < sizeof (variables); i++)
    {
      if (variables[i] == varName)
        return startOffset + i;
      else if (variables[i] == '\0')
        {
          variables[i] = varName;
          return startOffset + i;
        }
    }
  return -1;
}