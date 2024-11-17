#pragma once
#include "../include/mySimpleComputer.h"
#include "../mySimpleComputer/sc.h"
#include "sb_variables.h"
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>

int compileBasic (FILE *file_sb, FILE *file_sa, char **argv, int flag);

char sb_getVariableName (int variableAddress, int nameOffset);
int sb_getGotoAddr (int gotoLine);
void sb_clearBackspace (char *str);
int sb_findOrCreateVariableAddress (char varName, int startOffset);
int sb_memorySet (int address, int value);

void handleEnd ();
void handleInput ();
void handleLet ();
void handleIf ();
void handleGoto ();
void handlePrint ();

void postprocessJumps (int i);
void postprocessCommands (int i);
void postprocessHalt (int i);
void postprocessVariables (int i);

extern int var_offset, strnum, asm_addr, last_strnum;
extern int max_strnum, goto_addr, goto_line;
extern char opr[6], str[100], ch;
extern char line[100];
extern int linenum;