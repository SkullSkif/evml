#include <mySimpleComputer.h>
#include <sc.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 100
#define MAX_COMMENT_LENGTH 10
#define MEMORY_SIZE 128

// Структура для хранения кодов команд
typedef struct
{
  const char *name;
  int code;
} Command;

// Функция для проверки диапазона адресов и значений
bool isValidRange(int addr, int value)
{
  return (addr < 0 || addr > MEMORY_SIZE || value < 0 || value > 65535);
}

// Функция для установки значения в памяти
int memorySet(int addr, int value)
{
  if (isValidRange(addr, value))
  {
    sc_regSet(OUT_OF_MEMORY_BOUNDS, 1);
    printf("OUT_OF_MEMORY_BOUNDS, address: %x\n", addr);
    return -1;
  }

  memory[addr] = value;
  return 0;
}

// Функция для валидации команды
int commandValidate(char *command)
{
  Command commands[] = {{"NOP", 0x00}, {"CPUINFO", 0x01}, {"READ", 0x0A}, {"WRITE", 0x0B}, {"LOAD", 0x14}, {"STORE", 0x15}, {"ADD", 0x1E}, {"SUB", 0x1F}, {"DIVIDE", 0x20}, {"MUL", 0x21}, {"JUMP", 0x28}, {"JNEG", 0x29}, {"JZ", 0x2A}, {"HALT", 0x2B}, {"JNS", 0x37}, {"JP", 0x3A}, {"SUBC", 0x42}};
  int numCommands = sizeof(commands) / sizeof(commands[0]);

  for (int i = 0; i < numCommands; ++i)
  {
    if (strcmp(command, commands[i].name) == 0)
    {
      return commands[i].code;
    }
  }

  if (command[0] == '=')
  {
    return 1;
  }

  return -1;
}

int main(int argc, char **argv)
{
  FILE *source_file;

  if (argc != 3)
  {
    printf("Usage: %s source_file.sa output_file.o\n", argv[0]);
    return -1;
  }
  if ((source_file = fopen(argv[1], "rb")) == NULL)
  {
    printf("Can't open '%s' file.\n", argv[1]);
    return -1;
  }

  printf("Source file is open\n");

  sc_memoryInit();

  char line[MAX_LINE_LENGTH];
  char comment[MAX_COMMENT_LENGTH];
  char operand_str[MAX_COMMENT_LENGTH];
  char comment_line[MAX_LINE_LENGTH] = "\0";

  int address, command, operand, encoded_value;

  while (!feof(source_file))
  {
    fgets(line, sizeof(line), source_file);
    if (feof(source_file))
    {
      break;
    }
    if (sscanf(line, "%d %s %s ;%s", &address, comment, operand_str,
               comment_line) < 3)
    {
      printf("Invalid syntax in line: %s\n", line);
      fclose(source_file);
      return -1;
    }
    command = commandValidate(comment);
    printf("%d %d %s\n", address, command, operand_str);

    if (command != -1)
    {
      if (command != 1)
      {
        if (sscanf(operand_str, "%d", &operand) != 1 || sc_commandEncode(command, operand, &encoded_value) == -1 || memorySet(address, encoded_value) == -1)
        {
          printf("Invalid syntax\n");
          return -1;
        }
      }
      else
      {
        char sign;
        if (sscanf(operand_str, "%c%04X", &sign, &encoded_value) != 2)
        {
          printf("Invalid syntax\n");
          return -1;
        }
        if (sign == '-')
        {
          encoded_value = -encoded_value;
        }
        if (memorySet(address, encoded_value) == -1)
        {
          printf("Invalid syntax\n");
          return -1;
        }
      }
    }
    else
    {
      printf("Invalid syntax\n");
      return -1;
    }
  }

  fclose(source_file);

  if (sc_memorySave(argv[2]) == -1)
  {
    printf("Can't create '%s' file.\n", argv[2]);
    return -1;
  }

  printf("Output file '%s' created successfully.\n", argv[2]);
  return 0;
}
