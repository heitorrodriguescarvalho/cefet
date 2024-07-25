#include <stdio.h>
#include <stdlib.h>

main() {
  float valor, taxa, tempo;

  printf("Digite o valor: ");
  scanf("%f", &valor);

  printf("Digite a taxa: ");
  scanf("%f", &taxa);

  printf("Digite o tempo: ");
  scanf("%f", &tempo);

  printf("Valor da prestação: %f", valor + (valor * (taxa / 100) * tempo));
}