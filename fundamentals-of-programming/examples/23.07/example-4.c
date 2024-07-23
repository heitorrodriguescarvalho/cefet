#include <stdio.h>
#include <stdlib.h>

main() {
  int num, cont = 0, soma = 0;

  printf("Escreva um número inteiro (0 para parar): ");
  scanf("%d", &num);

  while (num != 0) {
    if (num % 2 == 0) {
      soma += num;
      cont++;
    }

  printf("Escreva um número inteiro (0 para parar): ");
  scanf("%d", &num);
  }

  printf("Média dos números pares informados: %f", (float)soma / cont);
}