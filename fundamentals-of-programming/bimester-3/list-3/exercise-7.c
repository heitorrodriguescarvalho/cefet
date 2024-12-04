#include <stdio.h>
#include <stdlib.h>

int Input_int(char text[])
{
  int num;

  do
  {
    printf(text);
    scanf("%d", &num);

    if (num % 2 == 1 && num > 0)
      break;
    else
      printf("O número deve ser ímpar e positivo\n");
  } while (1);

  return num;
}

int Double_factorial(int num)
{
  if (num <= 1)
    return num;

  return num * Double_factorial(num - 2);
}

int main()
{
  int num;

  num = Input_int("Escreva o número: ");

  printf("%d!! = %d", num, Double_factorial(num));

  return 0;
}