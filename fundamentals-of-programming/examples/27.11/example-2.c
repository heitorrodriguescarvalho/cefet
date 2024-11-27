#include <stdio.h>
#include <stdlib.h>

int Factorial(int num)
{
  if (num == 0)
    return 0;

  if (num == 1)
    return 1;

  return Factorial(num - 1) + Factorial(num - 2);
}

int main()
{
  int num;

  printf("Digite o último número da sequência: ");
  scanf("%d", &num);

  printf("Fibonnaci na %dº posição = %d", num, Factorial(num));

  return 0;
}