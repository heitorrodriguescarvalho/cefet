#include <stdio.h>
#include <stdlib.h>

float InputNum(char label[])
{
  float num;

  printf("%s", label);
  scanf("%f", &num);

  return num;
}

int main()
{
  float n1, n2, n3;

  n1 = InputNum("Digite o 1º número: ");
  n2 = InputNum("Digite o 2º número: ");
  n3 = InputNum("Digite o 3º número: ");

  printf("Resultado: %.2f", n1 * n1 + n2 + n3);

  return 0;
}