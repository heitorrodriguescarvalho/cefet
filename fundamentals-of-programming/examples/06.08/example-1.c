#include <stdio.h>
#include <stdlib.h>

main() {
  float valor[8];

  int i;

  float soma = 0,media;

  for (i = 0; i < 8; i++) {
    printf("%dº valor: ", i+1);
    scanf("%f", &valor[i]);
    soma += valor[i];
  }

  media = soma / 8;

  printf("\nMédia dos valores: %.2f", media);

  printf("\nValores acima da média: ");

  for (i = 0; i < 8; i++) {
    if (valor[i] > media) {
      printf("%.2f ", valor[i]);
    }
  }
}