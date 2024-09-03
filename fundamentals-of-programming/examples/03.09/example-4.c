#include <stdio.h>
#include <stdlib.h>

int main()
{
  int num[4][4], i, j;

  for (i = 0; i < 4; i++)
  {
    for (j = 0; j < 4; j++)
    {
      printf("Digite o %dº número da %dº linha: ", i + 1, j + 1);
      scanf("%d", &num[i][j]);
    }
  }

  printf("\nDiagonal Principal: ");
  for (i = 0; i < 4; i++)
  {
    printf("%d ", num[i][i]);
  }

  printf("\nDiagonal Secundária: ");
  for (i = 0; i < 4; i++)
  {
    printf("%d ", num[i][3 - i]);
  }
}