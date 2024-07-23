#include <stdio.h>
#include <stdlib.h>

main() {
  int cont;

  printf("Números divisíveis por 4 menores que 10.000:\n");

  for (cont = 0; cont < 10000; cont++) {
    if (cont % 4 == 0)
      printf("%d\n", cont);
  }
}