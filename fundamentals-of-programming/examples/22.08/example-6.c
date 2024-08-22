#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

main()
{
  char nome[100];
  int caracteres, i;

  printf("Escreva o nome: ");
  fgets(nome, 100, stdin);

  nome[strcspn(nome, "\n")] = '\0';

  for (i = 0; i < strlen(nome); i++)
  {
    printf("%s\n", nome);
  }
}