#include <stdio.h>
#include <stdlib.h>
#include <string.h>

main()
{
  char name[100];
  int i;

  printf("Escreva um nome: ");
  fgets(name, 100, stdin);

  for (i = 0; i < 10; i++)
  {
    printf("%s", name);
  }
}