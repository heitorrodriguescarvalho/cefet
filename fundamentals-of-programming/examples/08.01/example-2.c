#include <stdio.h>
#include <stdlib.h>

typedef struct
{
  int id;
  double balance;
} BankAccount;

void Init(BankAccount *account, int id, double balance)
{
  account->id = id;
  account->balance = balance;
}

void Deposit(BankAccount *account, int value)
{
  account->balance += value;
}

void Withdraw(BankAccount *account, int value)
{
  account->balance -= value;
}

void Print(BankAccount account)
{
  printf("\nId: %d\n", account.id);
  printf("Balance: %.2f", account.balance);
}

int main()
{
  BankAccount account;

  printf("Type the ID: ");
  scanf("%d", &account.id);

  printf("Type the initial balance: ");
  scanf("%lf", &account.balance);

  Deposit(&account, 50);
  Withdraw(&account, 80);

  Print(account);

  return 0;
}