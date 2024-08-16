#include <stdio.h>
#include <stdlib.h>

main()
{
  int vetor[12], x, y, soma = 0, i;

  printf("Digite os números do vetor:\n");
  for (i = 0; i < 12; i++)
  {
    printf("\t%dº número: ", i + 1);
    scanf("%d", &vetor[i]);
  }

  do
  {
    printf("Digite o valor da posição inicial: ");
    scanf("%d", &x);
  } while (x < 0 || x >= 12);

  do
  {
    printf("Digite o valor da posição final: ");
    scanf("%d", &y);
  } while (x < 0 || x >= 12 || y <= x);

  for (i = x; i <= y; i++)
  {
    soma += vetor[i];
  }

  printf("Soma dos valores: %d", soma);
}