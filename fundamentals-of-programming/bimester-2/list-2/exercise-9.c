#include <stdio.h>
#include <stdlib.h>

main()
{
  int vetor1[9], vetor2[9], vetor3[9], i;
  float media[9];

  printf("Digite os números do 1º vetor:\n");
  for (i = 0; i < 9; i++)
  {
    printf("\t%dº número: ", i + 1);
    scanf("%d", &vetor1[i]);
  }

  printf("Digite os números do 2º vetor:\n");
  for (i = 0; i < 9; i++)
  {
    printf("\t%dº número: ", i + 1);
    scanf("%d", &vetor2[i]);
  }

  printf("Digite os números do 3º vetor:\n");
  for (i = 0; i < 9; i++)
  {
    printf("\t%dº número: ", i + 1);
    scanf("%d", &vetor3[i]);
  }

  for (i = 0; i < 9; i++)
  {
    media[i] = (float)(vetor1[i] + vetor2[i] + vetor3[i]) / 3;
  }

  printf("Vetor: ");
  for (i = 0; i < 9; i++)
  {
    printf("%.2f\t", media[i]);
  }
}