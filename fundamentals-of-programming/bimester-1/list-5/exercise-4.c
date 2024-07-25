#include <stdio.h>
#include <stdlib.h>

main() {
  float years, price;
  int cigarettes;

  printf("Há quantos anos você fuma: ");
  scanf("%f", &years);

  printf("Quantos cigarros você fuma por dia: ");
  scanf("%d", &cigarettes);

  printf("Qual o preço de uma cartela com 20 cigarros: ");
  scanf("%f", &price);

  printf("Quantidade de dinheiro gasta: R$%.2f", (cigarettes * (price / 20)) * 365 * years);
}