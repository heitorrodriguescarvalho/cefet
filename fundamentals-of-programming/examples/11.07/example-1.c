#include <stdio.h>
#include <stdlib.h>

main() {
  float media1 = (7 + 8 + 9) / 3;
  float media2 = (4 + 5 + 6) / 3;

  printf("Média aritmética de 7, 8, e 9: %f\n", media1);
  printf("Média aritmética de 4, 5, e 6: %f\n", media2);
  printf("Soma das médias: %f\n", media1 + media2);
  printf("Média das médias: %f", (media1 + media2) / 2);
}