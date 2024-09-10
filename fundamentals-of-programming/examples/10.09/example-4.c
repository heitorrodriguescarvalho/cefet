#include <stdio.h>
#include <stdlib.h>

main()
{
  int matriz[3][3], linhas[3], colunas[3], i, j, linha, coluna;

  for (i = 0; i < 3; i++)
  {
    for (j = 0; j < 3; j++)
    {
      printf("Digite o %dº valor da %dº linha: ", i + 1, j + 1);
      scanf("%d", &matriz[i][j]);
    }
  }

  for (i = 0; i < 3; i++)
  {
    linha = 0;
    coluna = 0;

    for (j = 0; j < 3; j++)
    {
      linha += matriz[i][j];
      coluna += matriz[j][i];
    }

    linhas[i] = linha;
    colunas[i] = coluna;
  }

  printf("Soma das linhas: ");
  for (i = 0; i < 3; i++)
  {
    printf("%d ", linhas[i]);
  }

  printf("Soma das colunas: ");
  for (i = 0; i < 3; i++)
  {
    printf("%d ", colunas[i]);
  }
}