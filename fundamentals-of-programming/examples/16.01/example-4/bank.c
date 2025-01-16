#include <stdio.h>
#include <stdlib.h>
#include "bank.h"

void Init(BankAccount *account, int id, char name[], double balance)
{
  account->id = id;
  account->name;
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
  printf("\nNº da conta: %d\nSaldo: %.2f\n", account.id, account.balance);
}