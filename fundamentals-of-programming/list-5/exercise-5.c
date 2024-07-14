#include <stdio.h>
#include <stdlib.h>

main() {
  int x, y;

  printf("Digite dois números inteiros:\n");
  scanf("%d %d", &x, &y);

  printf("Quociente: %d\n", x / y);
  printf("Resto: %d\n", x % y);
}