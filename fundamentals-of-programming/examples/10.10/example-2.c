#include <stdio.h>
#include <stdlib.h>

void IncrementAndLog(int num)
{
  num++;

  printf("Número na função: %d\n", num);
}

main()
{
  int num;

  printf("Digite um número: ");
  scanf("%d", &num);

  IncrementAndLog(num);

  printf("Número no main: %d", num);
}