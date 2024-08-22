#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

main()
{
  char nome[100], sexo[10];
  int idade, i;

  printf("Escreva o nome: ");
  fgets(nome, 100, stdin);

  printf("Escreva o sexo (masculino|feminino): ");
  fgets(sexo, 10, stdin);

  for (i = 0; i < strlen(sexo); i++)
  {
    sexo[i] = tolower(sexo[i]);
  }

  sexo[strcspn(sexo, "\n")] = '\0';
  nome[strcspn(nome, "\n")] = '\0';

  if (strcmp(sexo, "masculino") != 0 && strcmp(sexo, "feminino") != 0)
  {
    printf("Sexo inválido");
  }
  else
  {
    printf("Escreva a idade: ");
    scanf("%d", &idade);

    if (strcmp(sexo, "feminino") == 0 && idade < 25)
    {
      printf("%s - Aceita", nome);
    }
    else
    {
      printf("Não aceita");
    }
  }
}