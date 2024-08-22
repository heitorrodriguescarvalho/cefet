#include <stdio.h>
#include <stdlib.h>
#include <string.h>

main()
{
  char name[100];

  printf("Escreva um nome: ");
  fgets(name, 100, stdin);

  if (strlen(name) < 5)
  {
    printf("O nome deve ter pelo menos quatro caracteres");
  }
  else
  {
    printf("%.4s", name);
  }
}