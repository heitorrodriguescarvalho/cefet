#include <stdio.h>
#include <stdlib.h>

main()
{
  int vetor[8], num, existe = 0, i;

  printf("Digite os números do vetor:\n");
  for (i = 0; i < 8; i++)
  {
    scanf("%d", &vetor[i]);
  }

  printf("Digite o número de busca: ");
  scanf("%d", &num);

  for (i = 0; i < 8; i++)
  {
    if (vetor[i] == num)
    {
      printf("Posição do número: %d", i);
      existe = 1;
    }
  }

  if (existe == 0)
    printf("O número não foi encontrado");
}