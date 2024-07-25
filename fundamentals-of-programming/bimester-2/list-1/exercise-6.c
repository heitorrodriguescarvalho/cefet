#include <stdio.h>
#include <stdlib.h>

main() {
  int cont;

  for (cont = 1; cont <= 1000; cont++) {
    if (cont % 4 == 0)
      printf("%d\n", cont);
  }
}