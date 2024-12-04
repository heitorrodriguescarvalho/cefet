#include <stdio.h>
#include <stdlib.h>

int Input_int(char text[])
{
  int num;

  printf(text);
  scanf("%d", &num);

  return num;
}

int Sum(int num, int count)
{
  if (count == num)
    return num;

  return count + Sum(num, count + 1);
}

int main()
{
  int num;

  num = Input_int("Escreva o número: ");

  printf("Soma dos números de -10 a %d: %d", num, Sum(num, -10));

  return 0;
}