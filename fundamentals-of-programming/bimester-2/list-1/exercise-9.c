#include <stdio.h>
#include <stdlib.h>

main() {
  int num;

  printf("Digite um número: ");
  scanf("%d", &num);

  if (num > 154 && num < 18745321) {
    printf("O número %d está compreendido entre 154 e 18.745.321", num);
  } else {
    printf("O número %d não está compreendido entre 154 e 18.745.321", num);
  }
}