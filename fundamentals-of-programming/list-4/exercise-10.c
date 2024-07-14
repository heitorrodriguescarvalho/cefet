#include <stdio.h>
#include <stdlib.h>
#include <math.h>

main() {
  float raio;

  printf("Digite o raio: ");
  scanf("%f", &raio);

  printf("Perímetro: %f\nRaio: %f", 2 * M_PI * raio, M_PI * pow(raio, 2));
}