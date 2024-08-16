#include <stdio.h>
#include <stdlib.h>

main()
{
  int matriculas[10], matricula, i, k, existe = 0;

  printf("Digite as matrículas:\n");
  for (i = 0; i < 10; i++)
  {
    printf("\t%dº matrícula: ", i + 1);
    scanf("%d", &matriculas[i]);
  }

  printf("\nConsulte as matrículas:\n");

  for (i = 0; i < 3; i++)
  {
    printf("\n%dº matrícula: ", i + 1);
    scanf("%d", &matricula);

    for (k = 0; k < 10; k++)
    {
      if (matriculas[k] == matricula)
      {
        printf("A matrícula existe");
        existe = 1;
      }
    }

    if (existe == 0)
    {
      printf("A matrícula não existe");
    }

    existe = 0;
  }
}