#include <stdio.h>
#include <stdlib.h>

int Multiplication(int num, int cont)
{
  if (cont == 1)
  {
    return num;
  }

  return num + Multiplication(num, cont - 1);
}

int main()
{
  int n1, n2;

  printf("Digite o 1º fator: ");
  scanf("%d", &n1);

  printf("Digite o 2º fator: ");
  scanf("%d", &n2);

  printf("%d x %d = %d", n1, n2, Multiplication(n1, n2));

  return 0;
}