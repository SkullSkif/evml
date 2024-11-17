#include <sb_variables.h>
#include <simplebasic.h>

int
sb_getVarAddr (char varName, int offset)
{
  size_t i;
  for (i = 0; i < sizeof (variables); i++)
    {
      if (variables[i] == varName || variables[i] == '\0')
        {
          variables[i] = varName;
          return offset + i;
        }
    }
  return -1; // Ошибка: переменная не найдена и нет места для добавления новой.
}