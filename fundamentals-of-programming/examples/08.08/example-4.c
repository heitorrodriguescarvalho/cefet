#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

main() {
  int nums[10];
  int cont, num;
  bool temMult = false;

  printf("Escreva os números do vetor:\n");

  for (cont = 0; cont < 10; cont++) {
    printf("%dº valor: ", cont + 1);
    scanf("%d", &nums[cont]);
  }

  printf("Múltiplos de 3:\n");

  for (cont = 0; cont < 10; cont++) {
    if (nums[cont] % 3 == 0) {
      temMult = true;
      printf("%d ", nums[cont]);
    }
  }

  if (!temMult) {
    printf("Nenhum valor é múltiplo de 3");
  }
}