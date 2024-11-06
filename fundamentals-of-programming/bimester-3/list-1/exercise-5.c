#include <stdio.h>
#include <stdlib.h>

int IncrementAndPrint(int num)
{
  printf("Número na função: %d\n", ++num);

  return num;
}

int main()
{
  int num;

  printf("Digite um número: ");
  scanf("%d", &num);

  int numIncremented = IncrementAndPrint(num);

  printf("Número retornado da função: %d\n", numIncremented);
  printf("Número da variável original: %d\n", num);

  return 0;
}