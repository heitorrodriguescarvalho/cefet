#include <stdio.h>
#include <stdlib.h>

main() {
  int cont = 0, num;

  do {
    printf("Digite um número: ");
    scanf("%d", &num);

    if (num % 2 == 0) cont++;
  } while (num != -1);

  printf("Quantidade de números pares: %d", cont);
}