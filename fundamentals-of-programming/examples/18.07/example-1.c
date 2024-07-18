#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
  int vetor, num, i, j;

  printf("Digite a quantidade de números no vetor: ");
  scanf("%d", &vetor);

  int nums[vetor];

  printf("Digite os números:\n");
  for (i = 0; i < vetor; i++) {
    scanf("%d", &num);
    nums[i] = num;
  }

  int menor, posicao, substitui;
  for (i = 0; i < vetor; i++) {
    menor = INFINITY;

    for (j = i; j < vetor; j++) {
      if (nums[j] < menor) {
        menor = nums[j];
        posicao = j;
      }
    }

    substitui = nums[i];
    nums[i] = menor;
    nums[posicao] = substitui;
  }

  printf("Números organizados: ");

  for (i = 0; i < vetor; i++) {
    printf("%d ", nums[i]);
  }
}