#include <stdio.h>
#include <stdlib.h>
#include "bank.h"

void Init(BankAccount *account, int id, double balance)
{
  account->id = id;
  account->balance = balance;
}

void Deposit(BankAccount *account, double amount)
{
  account->balance += amount;
}

void Withdraw(BankAccount *account, double amount)
{
  account->balance -= amount;
}

void Print(BankAccount account)
{
  printf("\nId: %d\nBalance: %lf", account.id, account.balance);
}