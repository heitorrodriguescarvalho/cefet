#include <stdio.h>
#include <stdlib.h>

main() {
  float salario, prestacao;

  printf("Digite o seu salário: ");
  scanf("%f", &salario);

  printf("Digite o valor da prestação: ");
  scanf("%f", &prestacao);

  if ((salario * 0.2) >= prestacao) {
    printf("Empréstimo concedido");
  } else {
    printf("Emprestimo negado");
  }
}