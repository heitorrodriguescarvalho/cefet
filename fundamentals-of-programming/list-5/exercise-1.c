#include <stdio.h>
#include <stdlib.h>

main() {
  float side1, side2, side3;

  printf("Digite a medida dos três lados do triângulo:\n");
  scanf("%f %f %f", &side1, &side2, &side3);

  if (side1 >= side2 + side3 ||
    side2 >= side1 + side3 ||
    side3 >= side1 + side2)
    printf("A medida dos lados fornecidos não formam um triângulo.");
  else {
    if (side1 == side2 && side2 == side3)
      printf("O triângulo é equilátero.");
    else if (side1 == side2 || side2 == side3 || side1 == side3)
      printf("O triângulo é isóceles.");
    else
      printf("O triângulo é escaleno.");
  }
}