#include <stdio.h>
#include <stdlib.h>
#include "bank.h"

int main()
{
  BankAccount account;

  Init(&account, 918273, 200.19);

  Print(account);

  Deposit(&account, 0.81);

  Print(account);

  Withdraw(&account, 100);

  Print(account);

  return 0;
}