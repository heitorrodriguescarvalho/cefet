#include <stdio.h>
#include <stdlib.h>

int Soma(int a, int b)
{
  return a + b;
}

int Subtracao(int a, int b)
{
  return a - b;
}

int Multiplicacao(int a, int b)
{
  return a * b;
}

float Divisao(int a, int b)
{
  if (b == 0)
    return 0;

  return (float)a / b;
}

void Print(int a, int b, float result, char symbol)
{
  printf("%d %c %d = %.2f\n", a, symbol, b, result);
}

main()
{
  int n1, n2;

  printf("Digite dois números:\n");
  scanf("%d %d", &n1, &n2);

  Print(n1, n2, (float)Soma(n1, n2), '+');
  Print(n1, n2, (float)Subtracao(n1, n2), '-');
  Print(n1, n2, (float)Multiplicacao(n1, n2), '*');
  Print(n1, n2, Divisao(n1, n2), '/');
}