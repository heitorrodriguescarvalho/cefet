#include <stdio.h>
#include <stdlib.h>

main() {
  int cont;

  printf("Múltiplos de 3 e 5 entre 0 e 1.000: \n");

  for (cont = 1; cont < 1000; cont++) {
    if (cont % 3 == 0 && cont % 5 == 0)
      printf("%d\n", cont);
  }
}