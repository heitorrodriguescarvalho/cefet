#include <stdio.h>
#include <stdlib.h>
#include "user.h"

void Get_user(User *user)
{
  printf("Digite o nome: ");
  setbuf(stdin, NULL);
  fgets(user->name, 50, stdin);

  printf("Digite a idade: ");
  scanf("%d", &user->age);

  printf("Digite o endereço: ");
  setbuf(stdin, NULL);
  fgets(user->address, 100, stdin);
}

void Print_user(User user)
{
  printf("\nNome: %s", user.name);
  printf("Idade: %d", user.age);
  printf("\nEndereço: %s", user.address);
}