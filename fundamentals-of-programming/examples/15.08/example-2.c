#include <stdio.h>
#include <stdlib.h>

main()
{
  int vetor[8], num, i, posicao = -1;

  printf("Preencha o vetor:\n");

  for (i = 0; i < 8; i++)
  {
    scanf("%d", &vetor[i]);
  }

  printf("Digite o número que será pesquisado: ");
  scanf("%d", &num);

  for (i = 0; i < 8; i++)
  {
    if (vetor[i] == num)
      posicao = i;
  }

  if (posicao == -1)
    printf("O número não existe no vetor");
  else
    printf("O número está na posição %d", posicao);
}