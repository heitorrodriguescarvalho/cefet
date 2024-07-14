#include <stdio.h>
#include <stdlib.h>

main() {
  int code, dependents;
  float hours, salary, inss, ir;

  printf("Digite seu código: ");
  scanf("%d", &code);

  printf("Digite o número de horas trabalhadas: ");
  scanf("%f", &hours);

  printf("Digite seu número de dependentes: ");
  scanf("%d", &dependents);

  salary = hours * 12;
  inss = salary * 0.085;
  salary -= inss;
  ir = salary * 0.05;
  salary -= ir;

  printf("Desconto do INSS: R$%.2f\n", inss);
  printf("Desconto do IR: R$%.2f\n", ir);
  printf("Salário líquido: R$%.2f\n", salary);
}