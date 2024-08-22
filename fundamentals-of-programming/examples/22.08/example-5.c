#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

main()
{
  char nome[100];
  int letras;

  printf("Escreva o nome: ");
  fgets(nome, 100, stdin);

  nome[strcspn(nome, "\n")] = '\0';

  printf("'%s' tem %d letras", nome, strlen(nome));
}