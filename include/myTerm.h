#pragma once
#include <stdio.h>
#include <sys/ioctl.h>

enum Colors
{
  BLACK,
  RED,
  GREEN,
  BLUE,
  MAGNETA,
  CYAN,
  GRAY,
  WHITE
};

int mt_clrscrn ();

int mt_gotoXY (int col, int row);

int mt_getscreensize (int *rows, int *cols);

int mt_setfgcolor (enum Colors color);

int mt_setbgcolor (enum Colors color);

int mt_setdefaultcolor ();

int mt_set_cursorvisible (int value);

int mt_delline ();
