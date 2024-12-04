#include <stdio.h>
#include <stdlib.h>

int Input_int(char text[])
{
  int num;

  printf(text);
  scanf("%d", &num);

  return num;
}

void Print_range(int num, int count)
{
  printf("%3d", count);

  if (count < num - 1)
    Print_range(num, count + 2);
}

int main()
{
  int num;

  num = Input_int("Escreva o número: ");

  printf("Números de 0 a %d:\n", num);

  Print_range(num, 0);

  return 0;
}