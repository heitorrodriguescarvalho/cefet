#include <stdio.h>
#include <stdlib.h>

main() {
  int dividendo, divisor;

  printf("Digite o dividendo: ");
  scanf("%d", &dividendo);

  printf("Digite o divisor: ");
  scanf("%d", &divisor);

  printf("Dividendo: %d\nDIvisor: %d\nQuociente: %d\nResto: %d", dividendo, divisor, dividendo / divisor, dividendo % divisor);
}