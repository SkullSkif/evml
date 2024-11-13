#pragma once
#include "../include/myBigChars.h"
#include "../include/mySimpleComputer.h"
#include "../include/myTerm.h"

#define memoryCell = 6;
#define FLAGS = 16;
#define Decoded = 32;
#define Accumulator = 16;
#define Counter = 16;
#define Command = 16;
#define in_out = 11;
#define clavs = 17;
#define cache = 56;
#define memroyCellsY = 10;

extern int IN_OUT_addres[4];
extern int IN_OUT_command[4];
extern int font[18][2];

void printCell (int address, enum Colors fg, enum Colors bg);

void printFlags ();

void printAccumulator ();

void printCounters ();

void printTerm (int value, int input);

void printDecodedCommand (int value);

void printCommand ();

void printBigCell (int cell, int x, int y);

void printMemory ();

int generateFont ();