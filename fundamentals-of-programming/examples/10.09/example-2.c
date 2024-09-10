#include <stdio.h>
#include <stdlib.h>
#include <string.h>

main()
{
  char nome[100];
  int i;

  printf("Digite o nome: ");
  fgets(nome, 100, stdin);

  for (i = 0; i < strlen(nome) - 1; i++)
  {
    printf("%s", nome);
  }
}