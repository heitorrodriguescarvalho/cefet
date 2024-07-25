#include <stdio.h>
#include <stdlib.h>

main() {
  float balance;

  printf("Digite o saldo: R$");
  scanf("%f", &balance);

  printf("Novo saldo: R$%.2f", balance * 1.01);
}