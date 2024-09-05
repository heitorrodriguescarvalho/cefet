#include <stdio.h>
#include <stdlib.h>

int main()
{
  int num[4][2], i, j, x, y;

  for (i = 0; i < 4; i++)
  {
    for (j = 0; j < 2; j++)
    {
      printf("Digite o %dº número da %dº linha: ", j + 1, i + 1);
      scanf("%d", &num[i][j]);
    }
  }

  int maior = num[0][0];

  for (i = 0; i < 4; i++)
  {
    for (j = 0; j < 2; j++)
    {
      if (num[i][j] > maior)
      {
        maior = num[i][j];
        y = i;
        x = j;
      }
    }
  }

  printf("Coordenada do maior número: (%d, %d)", x, y);
}