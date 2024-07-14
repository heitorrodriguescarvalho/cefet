#include <stdio.h>
#include <stdlib.h>

main() {
  int quantity;
  float price, bonus, discount;

  printf("Escreva a quantidade de produtos: ");
  scanf("%d", &quantity);

  printf("Escreva o preço unitário do produto: ");
  scanf("%f", &price);

  float total = quantity * price;

  if (total < 100) {
    discount = 0.05;
  } else if (total >= 100 && total <= 1000) {
    discount = 0.05;
    bonus = total * 0.05;
  } else {
    discount = 0.1;
    bonus = total * 0.05;
    printf("Você foi cadastrado com Client Vip!\n");
  }

  printf("Valor a pagar: %.2f\n", total * (1 - discount));
}
