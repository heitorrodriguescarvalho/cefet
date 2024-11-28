#include <stdio.h>
#include <stdlib.h>

int Sum(int start, int end)
{
  if (start == end)
  {
    return start;
  }

  return start + Sum(start + 1, end);
}

int main()
{
  int start, end;

  printf("Digite o número de início: ");
  scanf("%d", &start);

  printf("Digite o número final: ");
  scanf("%d", &end);

  printf("Some de %d até %d = %d", start, end, Sum(start, end));

  return 0;
}