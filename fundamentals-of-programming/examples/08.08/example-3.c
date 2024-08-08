#include <stdio.h>
#include <stdlib.h>

main() {
  int nums1[10], nums2[10], nums3[10], nums4[10];
  int cont, num;

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

  printf("3º vetor:\n");
  for (cont = 0; cont < 10; cont++) {
    printf("%dº valor: ", cont + 1);
    scanf("%d", &nums3[cont]);
  }

  for (cont = 0; cont < 10; cont++) {
    nums4[cont] = nums1[cont] + nums2[cont] + nums3[cont];
  }

  printf("4º vetor (soma):\n");
  for (cont = 0; cont < 10; cont++) {
    printf("%d ", nums4[cont]);
  }
}