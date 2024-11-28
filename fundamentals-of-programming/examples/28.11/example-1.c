#include <stdio.h>
#include <stdlib.h>

int Sum(int num)
{
  if (num < 1)
  {
    return num;
  }

  return num + Sum(num - 1);
}

int main()
{
  int num;

  printf("Digite um número: ");
  scanf("%d", &num);

  printf("%d! = %d", num, Sum(num));

  return 0;
}