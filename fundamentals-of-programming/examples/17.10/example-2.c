#include <stdio.h>
#include <stdlib.h>

int Sum(int start, int end)
{
  int i, sum = 0;

  for (i = start; i <= end; i++)
    sum += i;

  return sum;
}

main()
{
  int n1, n2;

  printf("Digite o número inicial e final:\n");
  scanf("%d %d", &n1, &n2);

  printf("Somatório: %d", Sum(n1, n2));
}