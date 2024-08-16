#include <stdio.h>
#include <stdlib.h>

main()
{
  int vetor[10], num, i, cont = 0, soma = 0;

  printf("Preencha o vetor:\n");

  for (i = 0; i < 10; i++)
  {
    scanf("%d", &vetor[i]);
  }

  printf("Vetor Inverso: ");

  for (i = 9; i >= 0; i--)
  {
    printf("%d\t", vetor[i]);
  }
}