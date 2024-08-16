#include <stdio.h>
#include <stdlib.h>

main()
{
  int vetor[8], num, i;

  printf("Preencha o vetor:\n");

  for (i = 0; i < 8; i++)
  {
    scanf("%d", &vetor[i]);
  }

  printf("Digite o número que será somado: ");
  scanf("%d", &num);

  for (i = 0; i < 8; i++)
  {
    vetor[i] = vetor[i] + num;
  }

  printf("Vetor atualizado: ");
  for (i = 0; i < 8; i++)
  {
    printf("%d\t", vetor[i]);
  }
}