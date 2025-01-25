#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "auth.h"
#include "../utils/utils.h"
#include "../menu/menu.h"
#include "../account/account.h"
#include "../bank/bank-account/bank-account-menu.h"

Account *current_account;

void Select_auth_option()
{
  int input;

  while (1)
  {
    system("clear");
    printf("1. Entrar na sua conta\n2. Abrir uma conta\n3. Sair\n\nEscolha uma opção: ");
    scanf("%d", &input);

    switch (input)
    {
    case 1:
      Sign_in();
      break;
    case 2:
      Sign_up();
      break;
    case 3:
      return;
      break;
    default:
      Message("Entrada inválida...");
    }
  }
}

void Sign_in()
{
  int validPassword;
  Account *account;

  system("clear");

  account = Get_account_with_user_prompt("CPF: ");

  if (account == NULL)
    return;

  validPassword = Validate_password_with_user_prompt(account);

  if (!validPassword)
    return;

  current_account = account;

  Select_bank_option(&account->bank_account);
}

void Sign_up()
{
  int input;
  char name[100], id[30], password[80], confirmPassword[80];

  system("clear");

  printf("Nome: ");
  Input_string(name, 100);

  system("clear");

  while (1)
  {
    system("clear");

    printf("CPF: ");
    Input_string(id, 30);

    if (strlen(id) != 11)
    {
      input = Try_again("CPF deve conter 11 digitos.\n");

      if (!input)
        return;
    }
    else if (!IsNumeric(id))
    {
      input = Try_again("CPF deve conter apenas números.\n");

      if (!input)
        return;
    }
    else if (Get_account_by_id(id) != NULL)
    {
      input = Try_again("CPF já cadastrado...\n");

      if (!input)
        return;
    }
    else
    {
      break;
    }
  }

  while (1)
  {
    system("clear");

    printf("Senha: ");
    Input_string(password, 80);

    system("clear");

    printf("Confirme sua senha: ");
    Input_string(confirmPassword, 80);

    if (strcmp(password, confirmPassword) != 0)
    {
      input = Try_again("Senhas não conferem...\n");

      if (!input)
        return;
    }
    else
      break;
  }

  current_account = Create_account(name, id, password);
  Create_bank_account();

  Select_bank_option();
}

Account *Get_current_account()
{
  return current_account;
}