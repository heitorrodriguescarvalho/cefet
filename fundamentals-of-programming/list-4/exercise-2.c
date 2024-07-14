#include <stdio.h>
#include <stdlib.h>

main() {
  float n1, n2, n3;

  printf("Digite três números:\n");
  scanf("%f %f %f", &n1, &n2, &n3);

  printf("Média: %f", (n1 + n2 + n3) / 3);
}