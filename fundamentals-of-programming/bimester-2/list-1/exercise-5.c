#include <stdio.h>
#include <stdlib.h>

main() {
  int cont;

  for (cont = 1; cont <= 10000; cont++) {
    if (cont % 3 == 0 && cont % 5 == 0)
      printf("%d\n", cont);
  }
}