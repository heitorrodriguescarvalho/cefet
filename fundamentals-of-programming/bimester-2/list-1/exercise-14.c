#include <stdio.h>
#include <stdlib.h>

main() {
  int inicio, final, cont, soma = 0;

  printf("Digite o valor de início: ");
  scanf("%d", &inicio);

  printf("Digite o valor final: ");
  scanf("%d", &final);

  for (cont = inicio + 1; cont < final; cont++) {
    soma += cont;
  }

  printf("Soma dos números entre %d e %d: %d", inicio, final, soma);
}