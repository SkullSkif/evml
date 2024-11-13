#include <myTerm.h>
int
mt_gotoXY (int col, int row)
{
  if ((col == 0) || (row == 0))
    return -1;
  int X, Y;
  if (mt_getscreensize (&Y, &X) == 1)
    return -1;
  if ((Y < row) || (X < col))
    return -1;
  printf ("\033[%d;%dH", row, col);
  return 0;
}