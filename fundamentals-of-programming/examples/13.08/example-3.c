#include <stdio.h>
#include <stdlib.h>

main()
{
  int vetor[10], i;

  for (i = 0; i < 10; i++)
  {
    printf("Digite o %dº número do vetor: ", i + 1);
    scanf("%d", &vetor[i]);
  }

  int maior = vetor[0], menor = vetor[0], posicaoMaior = 0, posicaoMenor = 0;

  for (i = 0; i < 10; i++)
  {
    if (vetor[i] < menor)
    {
      menor = vetor[i];
      posicaoMenor = i;
    }

    if (vetor[i] > maior)
    {
      maior = vetor[i];
      posicaoMaior = i;
    }
  }

  printf("Maior:\n\tValor: %d\n\tPosição: %d\n\n", maior, posicaoMaior);
  printf("Menor:\n\tValor: %d\n\tPosição: %d\n\n", menor, posicaoMenor);
}