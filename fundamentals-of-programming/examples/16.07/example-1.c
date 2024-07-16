#include <stdio.h>
#include <stdlib.h>

main () {
  int num, cont, neg = 0;
  for (cont= 0; cont < 5; cont+=2) {
    printf("Digite um número inteiro: ");
    scanf("%d", &num);
    if (num < 0)
      neg++;
  }
  printf("O número de valores negativos é %d\n", neg);
}