#include <stdio.h>
#include <stdlib.h>

main()
{
  int vetor1[10], vetor2[10], mult[10], i;

  printf("Números do 1º vetor:\n");
  for (i = 0; i < 10; i++)
  {
    printf("\t%dº número: ", i + 1);
    scanf("%d", &vetor1[i]);
  }

  printf("Números do 2º vetor:\n");
  for (i = 0; i < 10; i++)
  {
    printf("\t%dº número: ", i + 1);
    scanf("%d", &vetor2[i]);
  }

  for (i = 0; i < 10; i++)
  {
    mult[i] = vetor1[i] * vetor2[i];
  }

  printf("Vetor: ");
  for (i = 0; i < 10; i++)
  {
    printf("%d\t", mult[i]);
  }
}