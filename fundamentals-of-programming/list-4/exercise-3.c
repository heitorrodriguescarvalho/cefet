#include <stdio.h>
#include <stdlib.h>

main() {
  int num;

  printf("Digite um número: ");
  scanf("%d", &num);

  printf("Sucessor: %d\nAntecessor: %d", num + 1, num - 1);
}