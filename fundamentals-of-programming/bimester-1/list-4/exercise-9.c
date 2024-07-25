#include <stdio.h>
#include <stdlib.h>

main() {
  float base, altura;

  printf("Digite a base e a altura, respectivamente:\n");
  scanf("%f %f", &base, &altura);

  printf("Perímetro: %.2f\nÁrea: %.2f", base * 2 + altura * 2, base * altura);
}