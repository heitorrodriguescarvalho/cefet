#ifndef BANK_ACCOUNT_H
#include "../stock/stock-db.h"
#include "../bond/bond-db.h"
#define BANK_ACCOUNT_H

typedef struct
{
  double reserved_balance;
  double balance;
  Stock stocks[50];
  Bond bonds[100];
  int last_bond_index;
} Bank_account;

Bank_account *Create_bank_account();
Bank_account *Get_current_bank_account();
void Deposit(double);
void Withdraw(double);
void Transfer(char[], double);

#endif