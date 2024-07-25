#include <stdio.h>
#include <stdlib.h>

main() {
  int pares = 0, impares = 0, num;

  do {
    printf("Digite um número (-1 para parar): ");
    scanf("%d", &num);

    if (num != -1) {
      if (num % 2 == 0)
        pares++;
      else
        impares++;
    }
  } while (num != -1);

  printf("Quantidade de ímpares: %d\n", impares);
  printf("Quantidade de pares: %d", pares);
}