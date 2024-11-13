#pragma once
#include <stdio.h>
#include <stdlib.h>

#define ON 0xFFFE
#define OFF 0x0001
#define IT_MASK 0x001
#define MC_MASK 0x1000
#define SF_MASK 0x010
#define ZD_MASK 0x10000
#define OO_MASK 0x100
#define MEMORY_SIZE 128

extern int memory[128];
extern int flags;
extern int Accum;
extern int ICount;

int sc_MemoryInit (void);
int sc_MemorySet (int address, int value);
int sc_MemoryGet (int address, int *value);
int sc_MemorySave (char *filename);
int sc_MemoryLoad (char *filename);
int sc_regInit (void);
int sc_regSet (int reg, int value);
int sc_regGet (int reg, int *value);
int sc_accumulatorInit (void);
int sc_accumulatorSet (int value);
int sc_accumulatorGet (int *value);
int sc_icounterInit (void);
int sc_icounterSet (int value);
int sc_icounterGet (int *value);
int sc_commandEncode (int sign, int command, int operand, int *value);
int sc_commandDecode (int value, int *sign, int *command, int *operand);
int sc_commandValidate (int command);