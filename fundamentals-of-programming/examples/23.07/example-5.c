#include <stdio.h>
#include <stdlib.h>

main() {
  int alunos, cont;
  float soma, n1, n2, n3, n4;

  printf("Digite a quantidade de alunos: ");
  scanf("%d", &alunos);

  for (cont = 1; cont <= alunos; cont++) {
    printf("Notas do %dº aluno:\n", cont);
    scanf("%f %f %f %f", &n1, &n2, &n3, &n4);

    printf("Média do %dº aluno: %f\n", cont, (float)(n1 + n2 + n3 + n4)/4);

    soma += (float)(n1 + n2 + n3 + n4)/4;
  }

  printf("Média geral da turma: %f", soma/alunos);
}