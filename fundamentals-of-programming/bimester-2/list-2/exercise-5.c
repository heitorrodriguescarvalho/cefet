#include <stdio.h>
#include <stdlib.h>

main()
{
  int vetor[12], x, y, i;

  printf("Digite os números do vetor:\n");
  for (i = 0; i < 12; i++)
  {
    printf("\t%dº número: ", i + 1);
    scanf("%d", &vetor[i]);
  }

  do
  {
    printf("Digite o valor da 1º posição: ");
    scanf("%d", &x);
  } while (x < 0 || x >= 12);

  do
  {
    printf("Digite o valor da 2º posição: ");
    scanf("%d", &y);
  } while (x < 0 || x >= 12);

  printf("Soma das posições: %d", vetor[x] + vetor[y]);
}