#include <stdio.h>
#include <stdlib.h>

int main()
{
  int a[2][3], b[2][3], c[2][3], i;

  printf("Matriz A:\n");

  for (i = 0; i < 6; i++)
  {
    printf("Digite o %dº número da %dº linha: ", i / 3 + 1, i % 3 + 1);
    scanf("%d", &a[i / 3][i % 3]);
  }

  printf("Matriz B:\n");

  for (i = 0; i < 6; i++)
  {
    printf("Digite o %dº número da %dº linha: ", i / 3 + 1, i % 3 + 1);
    scanf("%d", &b[i / 3][i % 3]);
  }

  for (i = 0; i < 6; i++)
  {
    c[i / 3][i % 3] = a[i / 3][i % 3] + b[i / 3][i % 3];
  }

  printf("Vetor C:\n");

  for (i = 0; i < 6; i++)
  {
    printf("%d ", c[i / 3][i % 3]);

    if (i % 3 == 2)
      printf("\n");
  }
}