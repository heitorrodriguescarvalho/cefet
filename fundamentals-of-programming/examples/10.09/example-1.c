#include <stdio.h>
#include <stdlib.h>
#include <string.h>

main()
{
  char alunos[5][30];
  float notas[5][4];
  float medias[5];
  int i, j, maior = 0;

  for (i = 0; i < 5; i++)
  {
    printf("Digite o nome do %dº aluno: ", i + 1);
    fgets(alunos[i], 30, stdin);
    if (alunos[i][strlen(alunos[i]) - 1] == '\n')
    {
      alunos[i][strlen(alunos[i]) - 1] = '\0';
    }
  }

  for (i = 0; i < 5; i++)
  {
    printf("Digite as notas de %s:\n", alunos[i]);

    for (j = 0; j < 4; j++)
    {
      printf("Digite a %dº nota: ", j + 1);
      scanf("%f", &notas[i][j]);
    }
  }

  for (i = 0; i < 5; i++)
  {
    medias[i] = 0;

    for (j = 0; j < 4; j++)
    {
      medias[i] += notas[i][j];
    }

    medias[i] /= 4;
  }

  for (i = 0; i < 5; i++)
  {
    if (medias[i] > medias[maior])
      maior = i;
  }

  printf("O aluno com a maior média é %s", alunos[maior]);
}