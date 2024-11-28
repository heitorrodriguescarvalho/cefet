#include <stdio.h>
#include <stdlib.h>

int Fibonacci(int num)
{
  if (num == 0)
    return 0;

  if (num == 1)
    return 1;

  return Fibonacci(num - 1) + Fibonacci(num - 2);
}

int main()
{
  int num;

  printf("Digite a posição do número na sequência: ");
  scanf("%d", &num);

  printf("Nº da sequência de Fibonacci na %dº posição: %d", num, Fibonacci(num));

  return 0;
}