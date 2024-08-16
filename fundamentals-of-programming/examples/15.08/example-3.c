#include <stdio.h>
#include <stdlib.h>

main()
{
  int vetor[10], i;

  for (i = 0; i < 10; i++)
  {
    vetor[i] = (i + 1) * 2;
  }

  printf("Vetor: ");

  for (i = 0; i < 10; i++)
  {
    printf("%d\t", vetor[i]);
  }
}