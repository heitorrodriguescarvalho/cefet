#include <stdio.h>
#include <stdlib.h>
#include "bank-account-menu.h"
#include "bank-account-db.h"
#include "../../account/account.h"
#include "../../auth/auth.h"
#include "../stock/stock-menu.h"
#include "../stock/stock-db.h"
#include "../../menu/menu.h"
#include "../../utils/utils.h"
#include "../order/order-menu.h"
#include "../bond/bond-menu.h"
#include "../bond/bond-db.h"

void Select_bank_option()
{
  int input;
  Account *account = Get_current_account();

  while (1)
  {
    system("clear");

    printf("Conta de %s\n\n1. Investir\n2. Depositar\n3. Sacar\n4. Transferir\n5. Ver saldo\n6. Sair\n\nEscolha uma opção: ", account->name);

    scanf("%d", &input);

    switch (input)
    {
    case 1:
      Select_investment_option();
      break;
    case 2:
      Deposit_menu();
      break;
    case 3:
      Withdraw_menu();
      break;
    case 4:
      Transfer_menu();
      break;
    case 5:
      Check_balance();
      break;
    case 6:
      return;
      break;
    default:
      Message("Entrada inválida...");
      break;
    }
  }
}

void Select_investment_option()
{
  int input;

  while (1)
  {
    system("clear");

    printf("1. Renda variável\n2. Renda fixa\n3. Ver ordens\n4. Ver posições\n5. Voltar\n\nEscolha uma opção: ");
    scanf("%d", &input);

    switch (input)
    {
    case 1:
      Stocks_pagination();
      break;
    case 2:
      Bonds_pagination();
      break;
    case 3:
      Orders_pagination();
      break;
    case 4:
      Select_positions_option();
      break;
    case 5:
      return;
      break;
    default:
      Message("Entrada inválida...");
      break;
    }
  }
}

void Deposit_menu()
{
  double amount;
  int input;

  amount = Get_amount("Valor do depósito: ", 0);

  if (amount == -1)
    return;

  input = Confirm("Confirmar depósito de R$%.2lf?", amount);

  if (!input)
    return;

  Deposit(amount);
}

void Withdraw_menu()
{
  double amount;
  int input;

  amount = Get_amount("Valor do saque: ", 1);

  if (amount == -1)
    return;

  input = Confirm("Confirmar saque de R$%.2lf?", amount);

  if (!input)
    return;

  Withdraw(amount);
}

void Transfer_menu()
{
  double amount;
  int input;
  Account *recipient_account;

  system("clear");

  recipient_account = Get_account_with_user_prompt("CPF do destinatário: ");

  if (recipient_account == NULL)
    return;

  amount = Get_amount("Valor da transferência: ", 1);

  if (amount == -1)
    return;

  input = Confirm("Confirmar transferência de R$%.2lf para %s?", amount, recipient_account->name);

  if (!input)
    return;

  Transfer(recipient_account->id, amount);
}

void Check_balance()
{
  int i, stock_count;
  double stock_amount = 0, bond_amount = 0;
  Bank_account *bank_account = Get_current_bank_account();
  Stock account_stock, stock;

  Update_bonds();

  stock_count = Count_current_user_owned_stocks();

  for (i = 0; i < stock_count; i++)
  {
    account_stock = Get_current_user_stock_by_index(i);
    stock = Get_stock_by_symbol(account_stock.symbol);

    stock_amount += stock.price_history[stock.last_price_index] * account_stock.quantity;
  }

  for (i = 0; i <= bank_account->last_bond_index; i++)
    bond_amount += bank_account->bonds[i].investment_value;

  system("clear");

  printf("Saldo por alocação\n\nAlocação | Quantia\n");

  for (i = 0; i < 9; i++)
    printf("-");

  printf("|");

  for (i = 0; i < 8; i++)
    printf("-");

  printf("\nAções    | R$%.2lf\nTítulos  | R$%.2f\nSaldo    | R$%.2f\n", stock_amount, bond_amount, bank_account->balance);

  for (i = 0; i < 9; i++)
    printf("-");

  printf("|");

  for (i = 0; i < 8; i++)
    printf("-");

  printf("\nTotal    | R$%.2f\n", stock_amount + bond_amount + bank_account->balance);

  Await_enter();
}

void Select_positions_option()
{
  int input;

  while (1)
  {
    system("clear");

    printf("Ver posições\n\n1. Ações\n2. Títulos\n3. Voltar\n\nEscolha uma opção: ");
    scanf("%d", &input);

    switch (input)
    {
    case 1:
      Stock_positions_pagination();
      break;
    case 2:
      Bond_positions_pagination();
      break;
    case 3:
      return;
      break;
    default:
      Message("Entrada inválida...");
      break;
    }
  }
}

// Helper functions
double Get_amount(char message[], int must_have_the_amount)
{
  double amount;
  int input;
  Bank_account *bank_account = Get_current_bank_account();

  while (1)
  {
    system("clear");

    printf("%sR$", message);
    scanf("%lf", &amount);

    if (amount <= 0)
    {
      input = Try_again("Valor inválido");

      if (!input)
        return -1;
    }
    else if (must_have_the_amount && amount > bank_account->balance)
    {
      input = Try_again("Saldo insuficiente");

      if (!input)
        return -1;
    }
    else
      break;
  }

  return amount;
}