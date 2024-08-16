#include <stdio.h>
#include <stdlib.h>

main()
{
  float notas[10];
  int i;

  printf("Digite as notas:\n");

  for (i = 0; i < 10; i++)
  {
    do
    {
      printf("\t%dº nota: ", i + 1);
      scanf("%f", &notas[i]);
    } while (notas[i] < 0 || notas[i] > 10);
  }

  float maior = notas[0], menor = notas[0], soma = 0;

  printf("\nNotas: ");

  for (i = 0; i < 10; i++)
  {
    printf("%.2f\t", notas[i]);

    if (notas[i] > maior)
      maior = notas[i];
    if (notas[i] < menor)
      menor = notas[i];
    soma += notas[i];
  }

  printf("\nMaior nota: %.2f\nMenor nota: %.2f\nMédia das notas: %.2f", maior, menor, soma / 10);
}