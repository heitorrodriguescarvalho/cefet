#include <stdio.h>
#include <stdlib.h>

main() {
  int nums[10];
  int cont, num;

  printf("Escreva os números do vetor:\n");

  for (cont = 0; cont < 10; cont++) {
    printf("%dº valor: ", cont + 1);
    scanf("%d", &nums[cont]);
  }

  printf("Escreva um número: ");
  scanf("%d", &num);

  printf("Números do vetor múltiplos de %d:\n", num);

  for (cont = 0; cont < 10; cont++) {
    if (nums[cont] % num == 0)
      printf("%d ", nums[cont]);
  }
}