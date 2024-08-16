#include <stdio.h>
#include <stdlib.h>

main()
{
  int vetor[8], num, i, cont = 0, soma = 0;

  printf("Preencha o vetor:\n");

  for (i = 0; i < 8; i++)
  {
    scanf("%d", &vetor[i]);
  }

  printf("Vetor: ");

  for (i = 0; i < 8; i++)
  {
    printf("%d\t", vetor[i]);
  }

  for (i = 0; i < 8; i++)
  {
    if (vetor[i] > 30)
    {
      cont++;
      soma += vetor[i];
    }
  }

  printf("\nNúmeros maiores que 30: %d", cont);
  printf("\nSoma dos números maiores que 30: %d", soma);
}