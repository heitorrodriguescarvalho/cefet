#include <stdio.h>
#include <stdlib.h>

main()
{
  int m[2][2], a, v[4], i, j;

  for (i = 0; i < 2; i++)
  {
    for (j = 0; j < 2; j++)
    {
      printf("Digite o %dº número da %dº linha: ", j + 1, i + 1);
      scanf("%d", &m[i][j]);
    }
  }

  printf("Escreva o valor que multiplicará a matriz: ");
  scanf("%d", &a);

  for (i = 0; i < 4; i++)
  {
    v[i] = m[i / 2][i % 2] * a;
  }

  printf("Vetor V: ");

  for (i = 0; i < 4; i++)
  {
    printf("%d ", v[i]);
  }
}