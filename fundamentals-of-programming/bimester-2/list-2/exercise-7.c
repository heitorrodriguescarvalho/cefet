#include <stdio.h>
#include <stdlib.h>

main()
{
  int vetor[16], x, y, i;

  printf("Digite os números do vetor:\n");
  for (i = 0; i < 16; i++)
  {
    printf("\t%dº número: ", i + 1);
    scanf("%d", &vetor[i]);
  }

  for (i = 0; i < 8; i++)
  {
    x = vetor[i];
    y = vetor[i + 8];

    vetor[i] = y;
    vetor[i + 8] = x;
  }

  printf("Vetor: ");
  for (i = 0; i < 16; i++)
  {
    printf("%d\t", vetor[i]);
  }
}