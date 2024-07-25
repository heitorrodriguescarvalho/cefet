#include <stdio.h>
#include <stdlib.h>

main() {
  int alunos, soma = 0, nota, cont;

  printf("Digite a quantidade de alunos: ");
  scanf("%d", &alunos);

  for (cont = 1; cont <= alunos; cont++) {
    printf("Digite a nota do %dº aluno: ", cont);
    scanf("%d", &nota);

    soma += nota;
  }

  printf("Média das notas: %f", (float)soma / alunos);
}