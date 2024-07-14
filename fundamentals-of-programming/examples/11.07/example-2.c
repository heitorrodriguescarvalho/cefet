#include <stdio.h>
#include <stdlib.h>

main() {
  float valorAula;
  int numAulas;
  float desconto;

  printf("Digite o valor de cada aula: ");
  scanf("%f", &valorAula);

  printf("Digite o número de aulas: ");
  scanf("%d", &numAulas);

  printf("Digite a porcentagem do desconto do INSS: ");
  scanf("%f", &desconto);  

  printf("Salário: R$%.2f", (numAulas * valorAula) * ((100 - desconto) / 100));
}