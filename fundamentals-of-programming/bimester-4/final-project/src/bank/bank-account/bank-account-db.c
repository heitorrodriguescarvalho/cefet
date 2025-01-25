#include <stdio.h>
#include <stdlib.h>
#include "bank-account-db.h"
#include "../../account/account.h"
#include "../../auth/auth.h"
#include "../stock/stock-db.h"

Bank_account *Create_bank_account()
{
  int i, stocks_length;
  Account *account = Get_current_account();
  Bank_account bank_account;

  bank_account.balance = 0;
  bank_account.reserved_balance = 0;

  stocks_length = Count_stocks();

  for (i = 0; i < stocks_length; i++)
  {
    bank_account.stocks[i] = Get_stock_by_index(i);
    bank_account.stocks[i].quantity = 0;
    bank_account.stocks[i].average_price = 0;
  }

  bank_account.last_bond_index = -1;

  account->bank_account = bank_account;

  return &account->bank_account;
}

Bank_account *Get_current_bank_account()
{
  Account *current_account = Get_current_account();

  return &current_account->bank_account;
}

void Deposit(double amount)
{
  Bank_account *bank_account = Get_current_bank_account();

  bank_account->balance += amount;
}

void Withdraw(double amount)
{
  Bank_account *bank_account = Get_current_bank_account();

  if (bank_account->balance < amount)
    return;

  bank_account->balance -= amount;
}

void Transfer(char recipient_id[], double amount)
{
  Bank_account *sender_bank_account = Get_current_bank_account();
  Bank_account *recipient_bank_account = &Get_account_by_id(recipient_id)->bank_account;

  if (sender_bank_account->balance < amount)
    return;

  sender_bank_account->balance -= amount;
  recipient_bank_account->balance += amount;
}