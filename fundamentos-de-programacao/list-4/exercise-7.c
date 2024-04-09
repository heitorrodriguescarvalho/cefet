#include <stdio.h>
#include <stdlib.h>

main() {
  float n1, n2, n3, n4;

  printf("Digite quatro números:\n");
  scanf("%f %f %f %f", &n1, &n2, &n3, &n4);

  printf("Média ponderada: %f", ((n1 * 1 + n2 * 2 + n3 * 3 + n4 * 4) / 10));
}