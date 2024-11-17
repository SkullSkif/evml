#include "simplebasic.h"

void
generateAssembly (int linenum, int strnum, int asm_addr, char *operation,
                  char var, char *newline)
{
  sprintf (asmString[asm_addr], "%d %d %d %s %c%s", linenum, strnum, asm_addr,
           operation, var, newline);
}

void
handleLet ()
{
  char *s = strstr (line, "LET") + 4;
  sb_clearBackspace (s);
  char targetVar, sourceVar1, sourceVar2, operator;
  int value;

  // Проверка на выражение в скобках
  if (sscanf (s, "%c=(%c%c%c)", &targetVar, &sourceVar1,
              &operator, & sourceVar2)
      == 4)
    {
      // Вычисление выражения в скобках
      generateAssembly (linenum, strnum, asm_addr, "LOAD", sourceVar1, "");
      asm_addr++;
      switch (operator)
        {
        case '+':
          generateAssembly (-1, -1, asm_addr, "ADD", sourceVar2, "\n");
          break;
        case '-':
          generateAssembly (-1, -1, asm_addr, "SUB", sourceVar2, "\n");
          break;
        case '*':
          generateAssembly (-1, -1, asm_addr, "MUL", sourceVar2, "\n");
          break;
        case '/':
          generateAssembly (-1, -1, asm_addr, "DIVIDE", sourceVar2, "\n");
          break;
        default:
          printf ("Invalid syntax\n");
          return;
        }
      asm_addr++;
      generateAssembly (-1, -1, asm_addr, "STORE", 'T',
                        "\n"); // Временная переменная для результата в скобках
      asm_addr++;

      // Загрузка результата выражения в скобках и выполнение операции с
      // использованием его
      generateAssembly (linenum, strnum, asm_addr, "LOAD", 'T', "");
      asm_addr++;
      generateAssembly (-1, -1, asm_addr, "MUL", sourceVar1, "\n");
      asm_addr++;
      generateAssembly (-1, -1, asm_addr, "STORE", targetVar, "\n");
      asm_addr++;
      last_strnum = strnum;
      linenum++;
      return;
    }

  // Обработка обычного выражения без скобок
  if (sscanf (s, "%c=%d", &targetVar, &value) == 2)
    {
      sprintf (asmString[asm_addr], "%d %d %d %s %d%s", linenum, strnum,
               asm_addr, "LOAD", value, "\n");
      asm_addr++;
      sprintf (asmString[asm_addr], "%d %d %d %s %c%s", -1, -1, asm_addr,
               "STORE", targetVar, "\n");
      asm_addr++;
      last_strnum = strnum;
      linenum++;
      return;
    }

  if (sscanf (s, "%c=%c%c%c", &targetVar, &sourceVar1, &operator, & sourceVar2)
      != 4)
    {
      printf ("Invalid syntax\n");
      return;
    }

  // Обработка обычного выражения без скобок
  generateAssembly (linenum, strnum, asm_addr, "LOAD", sourceVar1, "");
  asm_addr++;

  switch (operator)
    {
    case '+':
      generateAssembly (-1, -1, asm_addr, "ADD", sourceVar2, "\n");
      break;
    case '-':
      generateAssembly (-1, -1, asm_addr, "SUB", sourceVar2, "\n");
      break;
    case '*':
      generateAssembly (-1, -1, asm_addr, "MUL", sourceVar2, "\n");
      break;
    case '/':
      generateAssembly (-1, -1, asm_addr, "DIVIDE", sourceVar2, "\n");
      break;
    default:
      printf ("Invalid syntax\n");
      return;
    }

  asm_addr++;
  generateAssembly (-1, -1, asm_addr, "STORE", targetVar, "\n");
  asm_addr++;
  last_strnum = strnum;
  linenum++;
}
