#include <stdio.h>
#include <stdlib.h>

main() {
  int num, cont;

  printf("Digite o número: ");
  scanf("%d", &num);

  for (cont = 0; cont <= 10; cont++) {
    printf("%d x %d = %d\n", num, cont, num * cont);
  }
}