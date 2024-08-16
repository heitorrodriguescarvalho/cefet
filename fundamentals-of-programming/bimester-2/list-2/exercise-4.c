#include <stdio.h>
#include <stdlib.h>

main()
{
  int notas1[5], notas2[5], medias[5], i;

  printf("Digite as notas da 1º prova:\n");
  for (i = 0; i < 5; i++)
  {
    printf("\t%dº nota: ", i + 1);
    scanf("%d", &notas1[i]);
  }

  printf("\nDigite as notas da 2º prova:\n");
  for (i = 0; i < 5; i++)
  {
    printf("\t%dº nota: ", i + 1);
    scanf("%d", &notas2[i]);
  }

  for (i = 0; i < 5; i++)
  {
    medias[i] = ((float)notas1[i] + notas2[i]) / 2;
  }

  printf("\nResultado:\n");
  for (i = 0; i < 5; i++)
  {
    printf("\t%dº aluno: ", i + 1);

    if (medias[i] >= 6)
      printf("Aprovado\n");
    else
      printf("Reprovado\n");
  }
}