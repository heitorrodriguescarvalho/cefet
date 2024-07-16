#include <stdio.h>
#include <stdlib.h>

main () {
  int num, cont = 0, neg = 0;

  do {
    printf("Digite um número: ");
    scanf("%d", &num);

    if (num < 0)
      neg++;

    cont++;
  } while (cont < 5);

  printf("O número de valores negativos é %d", neg);
}