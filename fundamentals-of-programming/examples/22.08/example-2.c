#include <stdio.h>
#include <stdlib.h>
#include <string.h>

main()
{
  char name[100];
  int i;

  printf("Escreva um nome: ");
  fgets(name, 100, stdin);

  printf("Letras em posições ímpares: ");

  for (i = 1; i < strlen(name); i += 2)
  {
    printf("%c ", name[i]);
  }
}