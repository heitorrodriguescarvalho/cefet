#include <stdio.h>
#include <stdlib.h>
#include "bank.h"

int main()
{
  BankAccount account;
  char name[50];
  float balance, withdraw_value, deposit_value;
  int id;

  printf("Digite seu nome: ");
  setbuf(stdin, NULL);
  fgets(name, 50, stdin);

  printf("Digite o nº da conta: ");
  scanf("%d", &id);

  printf("Digite o saldo da conta: ");
  scanf("%f", &balance);

  Init(&account, id, name, balance);

  printf("\nValor do saque: R$");
  scanf("%f", &withdraw_value);

  Withdraw(&account, withdraw_value);

  printf("Valor do depósito: R$");
  scanf("%f", &deposit_value);

  Deposit(&account, deposit_value);

  Print(account);

  return 0;
}