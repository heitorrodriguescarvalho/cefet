#include <stdio.h>
#include <stdlib.h>

main()
{
  int vetor[40], cont = 0, i;

  printf("Digite os números do vetor:\n");
  for (i = 0; i < 40; i++)
  {
    printf("\t%dº número: ", i + 1);
    scanf("%d", &vetor[i]);
  }

  for (i = 0; i < 40; i++)
  {
    if (vetor[i] % 2 == 0)
      cont++;
  }

  printf("Quantidade de números pares: %d", cont);
}