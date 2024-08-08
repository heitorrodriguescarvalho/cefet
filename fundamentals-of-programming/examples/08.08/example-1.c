#include <stdio.h>
#include <stdlib.h>

main() {
  int nums[10];
  int cont, inicial, final;

  printf("Escreva os números do vetor:\n");

  for (cont = 0; cont < 10; cont++) {
    printf("%dº valor: ", cont + 1);
    scanf("%d", &nums[cont]);
  }

  printf("Escreva a posição inicial: ");
  scanf("%d", &inicial);

  printf("Escreva a posição final: ");
  scanf("%d", &final);


  printf("Valores compreendidos entre as posições %d e %d:\n", inicial, final);
  for (cont = inicial; cont <= final; cont++) {
    printf("%d ", nums[cont]);
  }
}