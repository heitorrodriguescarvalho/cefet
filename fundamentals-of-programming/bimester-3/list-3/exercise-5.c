#include <stdio.h>
#include <stdlib.h>

int Input_int(char text[])
{
  int num;

  printf(text);
  scanf("%d", &num);

  return num;
}

void Print_range(int num)
{
  printf("%3d", num);

  if (num > 0)
    Print_range(num - 1);
}

int main()
{
  int num;

  num = Input_int("Escreva o número: ");

  printf("Números de 0 a %d:\n", num);

  Print_range(num);

  return 0;
}