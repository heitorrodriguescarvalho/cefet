#include <stdio.h>
#include <stdlib.h>

main() {
  float saldo;

  printf("Digite o saldo: ");
  scanf("%f", &saldo);

  printf("Saldo reajustado: %.2f", saldo * 1.01);
}