#include <stdio.h>
#include <stdlib.h>

void SumAndPrint(int num)
{
  int i, sum = 0;

  for (i = 1; i <= num; i++)
  {
    sum += i;
  }

  printf("Soma entre 1 e %d: %d", num, sum);
}

main()
{
  int num;

  printf("Digite um número: ");
  scanf("%d", &num);

  SumAndPrint(num);
}