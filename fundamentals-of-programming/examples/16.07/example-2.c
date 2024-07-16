#include <stdio.h>
#include <stdlib.h>

main () {
  int num, cont = 0, neg = 0;

  while (cont < 5) {
    printf("Digite um número: ");
    scanf("%d", &num);

    if (num < 0)
      neg ++;

    cont++;
  }

  printf("O número de valores negativos é %d", neg);
}