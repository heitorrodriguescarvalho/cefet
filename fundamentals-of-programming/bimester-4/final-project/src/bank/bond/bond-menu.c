#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "bond-menu.h"
#include "bond-db.h"
#include "../bank-account/bank-account-menu.h"
#include "../bank-account/bank-account-db.h"
#include "../../menu/menu.h"
#include "../../utils/utils.h"

void Bonds_pagination()
{
  int i, j, input, pages, current_page = 0, initial_index, last_bond_index;
  Bond bond;

  last_bond_index = Count_bonds();

  pages = ceil(last_bond_index / 8.0);

  if (pages == 0)
    pages = 1;

  while (1)
  {
    system("clear");

    printf("Títulos (%d/%d):\n\n  |           Título           |            Taxa            | Rendimento\n", current_page + 1, pages);
    printf("--|----------------------------|----------------------------|------------\n");
    initial_index = current_page * 8;

    for (i = initial_index; i < initial_index + 8; i++)
    {
      bond = Get_bond_by_index(i);

      if (i > last_bond_index)
        break;

      printf("%d | ", i - initial_index + 2);
      printf("%s", bond.name);

      for (j = Count_UTF8_chars(bond.name); j < 26; j++)
        printf(" ");

      printf(" | ");

      printf("%s", bond.rate_label);

      for (j = Count_UTF8_chars(bond.rate_label); j < 26; j++)
        printf(" ");

      printf(" | ");

      printf("%5.2f%% a.a.\n", bond.annual_interest_rate * 100);
    }

    printf("\nUm mês do investimento equivale a 1 minuto real\n\n");

    if (current_page + 1 < pages)
      printf(" 1. Próxima página\n");

    if (current_page - 1 >= 0)
      printf(" 0. Página anterior\n");

    printf("-1. Voltar\n\nEscolha uma opção: ");
    scanf("%d", &input);

    switch (input)
    {
    case 1:
      if (current_page + 1 < pages)
        current_page++;
      else
        Message("Entrada inválida...");
      break;
    case 0:
      if (current_page - 1 >= 0)
        current_page--;
      else
        Message("Entrada inválida...");
      break;
    case -1:
      return;
      break;
    default:
      if (input >= 2 && input <= i - initial_index + 1)
        Select_bond_options(Get_bond_by_index(input + initial_index - 2).name);
      else
        Message("Entrada inválida...");
      break;
    }
  }
}

void Select_bond_options(char bond_name[])
{
  int input;
  Bond bond = Get_bond_by_name(bond_name);

  while (1)
  {
    system("clear");

    printf("Fundo: %s\n\n", bond.name);
    printf("Taxa: %s\n", bond.rate_label);
    printf("Rendimento: %.2f%% a.a.\n\n", bond.annual_interest_rate * 100);

    printf("1. Comprar\n2. Voltar\n\nEscolha uma opção: ");
    scanf("%d", &input);

    switch (input)
    {
    case 1:
      Buy_bond_options(bond.name);
      break;
    case 2:
      return;
      break;
    default:
      Message("Entrada inválida...");
      break;
    }
  }
}

void Buy_bond_options(char bond_name[])
{
  int input;
  double value;
  float years_to_expire;
  Bond bond = Get_bond_by_name(bond_name);

  while (1)
  {
    system("clear");

    printf("Comprando %s\n\n", bond.name);
    printf("Taxa: %s\n", bond.rate_label);
    printf("Rendimento: %.2f%%\n\n", bond.annual_interest_rate);

    value = Get_amount("Valor a ser aplicado: ", 1);

    if (value == -1)
      return;

    years_to_expire = Get_years("Tempo de aplicação: ", 1, 20);

    if (years_to_expire == -1)
      return;

    input = Confirm("Confirma a aplicação de R$%.2f em %s por %.2f anos?", value, bond.name, years_to_expire);

    if (!input)
      return;
    else
    {
      Buy_bond(bond.name, value, years_to_expire);
      return;
    }
  }
}

void Bond_positions_pagination()
{
  int i, j, input, pages, current_page = 0, initial_index, last_bond_index;
  Bond bond;
  Bank_account *bank_account;

  while (1)
  {
    Update_bonds();
    bank_account = Get_current_bank_account();

    last_bond_index = bank_account->last_bond_index;

    pages = ceil(last_bond_index / 8.0);

    if (pages == 0)
      pages = 1;

    system("clear");

    printf("Títulos (%d/%d):\n\n  |           Título           |            Taxa            | Rendimento  | Valor Investido | Prazo Deccorido (Meses) | Prazo Total (Meses)\n", current_page + 1, pages);
    printf("--|----------------------------|----------------------------|-------------|-----------------|-------------------------|--------------------\n");
    initial_index = current_page * 8;

    for (i = initial_index; i < initial_index + 8; i++)
    {
      bond = bank_account->bonds[i];

      if (i > last_bond_index)
        break;

      printf("%d | ", i - initial_index + 2);
      printf("%s", bond.name);

      for (j = Count_UTF8_chars(bond.name); j < 26; j++)
        printf(" ");

      printf(" | ");

      printf("%s", bond.rate_label);

      for (j = Count_UTF8_chars(bond.rate_label); j < 26; j++)
        printf(" ");

      printf(" | %5.2f%% a.a.", bond.annual_interest_rate * 100);
      printf(" | R$%-13.2f", bond.investment_value);
      printf(" | %15d mes(es)", bond.months_expired);

      if (bond.months_expired == bond.total_months_to_expire)
        printf(" - Vencido");

      printf(" | %13d meses\n", bond.total_months_to_expire);
    }

    printf("\n");

    if (current_page + 1 < pages)
      printf(" 1. Próxima página\n");

    if (current_page - 1 >= 0)
      printf(" 0. Página anterior\n");

    printf("-1. Voltar\n\nEscolha uma opção: ");
    scanf("%d", &input);

    switch (input)
    {
    case 1:
      if (current_page + 1 < pages)
        current_page++;
      else
        Message("Entrada inválida...");
      break;
    case 0:
      if (current_page - 1 >= 0)
        current_page--;
      else
        Message("Entrada inválida...");
      break;
    case -1:
      return;
      break;
    default:
      if (input >= 2 && input <= i - initial_index + 1)
        Select_bond_options(bank_account->bonds[initial_index + input - 2].name);
      else
        Message("Entrada inválida...");
      break;
    }
  }
}

// Helpers
float Get_years(char message[], float min, float max)
{
  float years;
  int input;

  while (1)
  {
    system("clear");

    printf("Restrições:\n\n\tMínimo: %.2f ano(s)\n\tMáximo: %.2f ano(s)\n\n%s", min, max, message);
    scanf("%f", &years);

    if (years < min || years > max)
    {
      input = Try_again("Valor inválido...");

      if (!input)
        return -1;
    }
    else
      break;
  }

  return years;
}