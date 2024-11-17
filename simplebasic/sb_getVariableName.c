#include "sb_variables.h"
#include "simplebasic.h"

char
sb_getVariableName (int variableAddress, int nameOffset)
{
  if (variableAddress - nameOffset >= 0
      && strcmp ((variables + variableAddress - nameOffset), "\0") != 0)
    {
      return variables[variableAddress - nameOffset];
    }
  return '\0';
}