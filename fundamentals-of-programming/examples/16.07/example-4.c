#include <stdio.h>
#include <stdlib.h>

main () {
  int cont = 0;
  float num, soma = 0;

  while (num >= 0) {
    printf("Digite um número positivo (ou negativo para encerrar): ");
    scanf("%f", &num);

  if (num >= 0) {
    soma += num;
    cont++;
    }
  }

  if (cont > 0) {
    printf("Média: %f\n", soma / cont);
  }
}