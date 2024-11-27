#include <stdio.h>
#include <stdlib.h>

int Factorial(long num)
{
  if (num == 0)
    return 1;

  return num * Factorial(num - 1);
}

int main()
{
  int num;

  printf("Digite o número do fatorial: ");
  scanf("%d", &num);

  printf("%d! = %ld", num, Factorial(num));

  return 0;
}