#include <stdio.h>
#include <stdlib.h>

main() {
  int nums1[10], nums2[10], soma[10];
  int cont;

  printf("Escreva os números dos vetores:\n");

  printf("1º vetor:\n");
  for (cont = 0; cont < 10; cont++) {
    printf("%dº valor: ", cont + 1);
    scanf("%d", &nums1[cont]);
  }

  printf("2º vetor:\n");
  for (cont = 0; cont < 10; cont++) {
    printf("%dº valor: ", cont + 1);
    scanf("%d", &nums2[cont]);
  }

  for (cont = 0; cont < 10; cont++) {
    soma[cont] = nums1[cont] + nums2[10 - cont -1];
  }

  printf("Vetor soma:\n");
  for (cont = 0; cont < 10; cont++) {
    printf("%d ", soma[cont]);
  }
}