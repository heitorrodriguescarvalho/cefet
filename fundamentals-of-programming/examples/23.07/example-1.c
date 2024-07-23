#include <stdio.h>
#include <stdlib.h>

main() {
  int cont, soma = 0;

  for (cont = 1; cont <= 100; cont++) {
    soma += cont;
  }

  printf("Soma dos 100 primeiros números inteiros: %d", soma);
}