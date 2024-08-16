#include <stdio.h>
#include <stdlib.h>

main()
{
  int vetor[10000], i = 0, final;

  printf("Digite os números do vetor (999 para):\n");
  do
  {
    scanf("%d", &vetor[i]);
    final = i;
    i++;
  } while (vetor[i - 1] != 999);

  printf("Vetor Inverso: ");

  for (i = final - 1; i >= 0; i--)
  {
    printf("%d\t", vetor[i]);
  }
}