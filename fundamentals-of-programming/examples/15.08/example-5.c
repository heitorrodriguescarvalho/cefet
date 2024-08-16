#include <stdio.h>
#include <stdlib.h>

main()
{
  int vetor[8], num, i, soma = 0, multiplos = 0, maior = 0, menor = 0;

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
    soma += vetor[i];

    if (vetor[i] % 5 == 0)
      multiplos++;

    if (vetor[i] > 10)
      maior++;
    if (vetor[i] < 30)
      menor++;
  }

  printf("\nMédia do vetor: %f\n", (float)soma / 8);
  printf("Quantidade de múltiplos de 5: %d\n", multiplos);
  printf("Quantidade de números maiores que 10: %d\n", maior);
  printf("Quantidade de números menores que 30: %d\n", menor);
}