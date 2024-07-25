#include <stdio.h>
#include <stdlib.h>

main() {
  float numerador, denominador;

  printf("Digite o numerador: ");
  scanf("%f", &numerador);

  printf("Digite o denominador: ");
  scanf("%f", &denominador);

  printf("Valor decimal: %f", numerador / denominador);
}