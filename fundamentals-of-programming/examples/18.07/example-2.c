#include <stdio.h>
#include <stdlib.h>

main() {
  int code, count=0;
  float sum=0, grade=0;

  printf("Digite o código do aluno: ");
  scanf("%d", &code);

  while(code != 0) {
    for (count = 0; count < 3; count++) {
      printf("Digite a %dº nota: ", count + 1);
      scanf("%f", &grade);

      sum += grade;
    }

    printf("Média do aluno: %.2f\n", sum / 3);

    printf("Digite o código do aluno: ");
    scanf("%d", &code);
  }
}