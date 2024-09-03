#include <stdio.h>
#include <stdlib.h>

int main()
{
  int num[3][4], i, j;

  for (i = 0; i < 3; i++)
  {
    for (j = 0; j < 4; j++)
    {
      num[i][j] = (i * 4) + j + 1;
    }
  }

  for (i = 0; i < 3; i++)
  {
    for (j = 0; j < 4; j++)
    {
      printf("%3d", num[i][j]);
    }
    printf("\n");
  }
}