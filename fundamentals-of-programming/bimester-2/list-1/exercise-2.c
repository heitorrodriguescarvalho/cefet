#include <stdio.h>
#include <stdlib.h>

main() {
  int cont;

  for (cont = 1; cont <= 20; cont++) {
    printf("%d² = %d\n", cont, cont * cont);
  }
}