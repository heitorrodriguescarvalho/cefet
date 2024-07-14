#include <stdio.h>
#include <stdlib.h>

main() {
  float balance;

  printf("Digite o seu saldo médio: ");
  scanf("%f", &balance);

  if (balance < 0)
    printf("Saldo médio inválido.");
  else if (balance <= 200)
    printf("Saldo médio: R$%.2f\nCrédito: R$%.2f", balance, 0.0);
  else if (balance <= 400)
    printf("Saldo médio: R$%.2f\nCrédito: R$%.2f", balance, balance * 0.2);
  else if (balance <= 600)
    printf("Saldo médio: R$%.2f\nCrédito: R$%.2f", balance, balance * 0.3);
  else
    printf("Saldo médio: R$%.2f\nCrédito: R$%.2f", balance, balance * 0.4);
}