#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "account.h"
#include "../menu/menu.h"
#include "../utils/utils.h"

// Database
Account accounts[50];
int last_account_index = 0;

// Database functions
Account *Create_account(char name[100], char id[12], char password[80])
{
  Account account;

  strcpy(account.id, id);
  strcpy(account.name, name);
  strcpy(account.password, password);

  accounts[last_account_index] = account;

  last_account_index++;

  return &accounts[last_account_index - 1];
}

Account *Get_account_by_id(char id[12])
{
  int accountIndex;

  for (accountIndex = 0; accountIndex < last_account_index; accountIndex++)
  {
    if (strcmp(accounts[accountIndex].id, id) == 0)
      return &accounts[accountIndex];
  }

  return NULL;
}

// Promp functions
Account *Get_account_with_user_prompt(char message[])
{
  Account *account;
  char id[20];
  int input;

  while (1)
  {
    system("clear");

    printf("%s", message);

    Input_string(id, 30);

    account = Get_account_by_id(id);

    if (account != NULL)
      return account;

    input = Try_again("Conta não encontrada...");

    if (!input)
      return NULL;
  }
}

int Validate_password_with_user_prompt(Account *account)
{
  char password[80];
  int input;

  while (1)
  {
    system("clear");

    printf("Senha: ");
    Input_string(password, 80);

    if (strcmp(account->password, password) == 0)
      return 1;

    input = Try_again("Senha incorreta...");

    if (!input)
      return 0;
  }
}
