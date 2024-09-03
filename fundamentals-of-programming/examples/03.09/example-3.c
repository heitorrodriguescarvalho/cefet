#include <stdio.h>
#include <stdlib.h>

int main()
{
  int num[3][3], i, j;

  for (i = 0; i < 3; i++)
  {
    for (j = 0; j < 3; j++)
    {
      printf("Digite o %dº número da %dº linha: ", i + 1, j + 1);
      scanf("%d", &num[i][j]);
    }
  }

  for (i = 0; i < 3; i++)
  {
    for (j = 0; j < 3; j++)
    {
      printf("%3d", num[i][j]);
    }
    printf("\n");
  }

  int maior = num[0][0], menor = num[0][0];

  for (i = 0; i < 3; i++)
  {
    for (j = 0; j < 3; j++)
    {
      if (num[i][j] > maior)
        maior = num[i][j];

      if (num[i][j] < menor)
        menor = num[i][j];
    }
  }

  printf("Maior: %d\nMenor: %d", maior, menor);
}