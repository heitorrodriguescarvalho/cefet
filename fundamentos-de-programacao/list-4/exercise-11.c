#include <stdio.h>
#include <stdlib.h>


main() {
  float base, altura;

  printf("Digite a base e a altura, respectivamente:\n");
  scanf("%f %f", &base, &altura);

  printf("Área do triângulo: %.2f", base * altura / 2);
}