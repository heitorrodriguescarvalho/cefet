#include <stdio.h>
#include <stdlib.h>

void PrintMatriz(int matriz[3][3], int cont)
{
  int i;
  for (i = 0; i <= cont; i++)
  {
    printf("%3d ", matriz[i / 3][i % 3]);

    if (i > 0 && (i + 1) % 3 == 0)
      printf("\n");
  }
}

main()
{
  int matriz[3][3], i, j;
  for (i = 0; i < 3; i++)
  {
    for (j = 0; j < 3; j++)
    {
      printf("\nDigite a %dº coluna da %d linha: ", j + 1, i + 1);
      scanf("%d", &matriz[i][j]);

      PrintMatriz(matriz, i * 3 + j);
    }
  }
}