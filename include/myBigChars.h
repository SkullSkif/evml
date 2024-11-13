#pragma once
#include "myTerm.h"
#include <errno.h>
#include <string.h>
#include <unistd.h>

#define BOXCHAR_REC "a"
#define BOXCHAR_DR "j"
#define BOXCHAR_DL "m"
#define BOXCHAR_UR "k"
#define BOXCHAR_UL "l"
#define BOXCHAR_VERT "x"
#define BOXCHAR_HOR "q"

int bc_strlen (char *str);
int bc_printA (char *str);
int bc_box (int x1, int y1, int x2, int y2, enum Colors box_fg,
            enum Colors box_bg, char *header, enum Colors header_fg,
            enum Colors header_bg);
int bc_setbigcharpos (int *big, int x, int y, int value);
int bc_getbigcharpos (int *big, int x, int y, int *value);
int bc_printbigchar (int *big, int x, int y, enum Colors fg, enum Colors bg);
int bc_bigcharwrite (int fd, int *big, int count);
int bc_bigcharread (int fd, int *big, int need_count, int *count);