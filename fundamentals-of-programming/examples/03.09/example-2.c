#include <stdio.h>
#include <stdlib.h>
#include <string.h>

main()
{
  char nomes[2][100];
  int i;

  for (i = 0; i < 2; i++)
  {
    printf("Digite o %dº nome: ", i + 1);
    fgets(nomes[i], 100, stdin);
  }

  printf("Nomes:\n%s%s", nomes[0], nomes[1]);
}