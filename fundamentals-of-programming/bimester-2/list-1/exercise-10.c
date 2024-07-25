#include <stdio.h>
#include <stdlib.h>

main() {
  int soma, cont;

  for (cont = 35; cont < 99; cont += 2)
    soma += cont;
  
  printf("Soma dos números ímpares entre 33 e 99: %d", soma);
}