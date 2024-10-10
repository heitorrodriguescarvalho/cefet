#include <stdio.h>
#include <stdlib.h>

float Sum(float n1, float n2)
{
  return n1 + n2;
}

float Subtract(float n1, float n2)
{
  return n1 - n2;
}

float Multiply(float n1, float n2)
{
  return n1 * n2;
}

float Divide(float n1, float n2)
{
  return (float)n1 / n2;
}

main()
{
  char operation;
  float n1, n2, result;

  printf("Digite dois números:\n");
  scanf("%f %f", &n1, &n2);

  printf("Digite o operador (+ - * /): ");
  scanf(" %c", &operation);

  switch (operation)
  {
  case '+':
    result = Sum(n1, n2);
    break;

  case '-':
    result = Subtract(n1, n2);
    break;

  case '*':
    result = Multiply(n1, n2);
    break;

  case '/':
    result = Divide(n1, n2);
    break;

  default:
    printf("Operador inválido");
  }

  printf("Resultado: %.2f", result);
}