#include <stdio.h>
#include <stdlib.h>

main() {
  int cont, soma = 0;

  for (cont = 34; cont < 99; cont++) {
    if (cont % 3 == 0 || cont % 5 == 0)
      soma += cont;
  }

  printf("Soma dos números múltiplos de 3 ou 5: %d", soma);
}