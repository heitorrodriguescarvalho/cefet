#include <stdio.h>
#include <stdlib.h>

float InputNum(char label[])
{
  float num;

  printf("%s", label);
  scanf("%f", &num);

  return num;
}

char InputCharacter(char label[])
{
  char character;

  printf("%s", label);
  scanf("%c", &character);

  return character;
}

float Calculate(float n1, float n2, char operation)
{
  switch (operation)
  {
  case '+':
    return n1 + n2;
  case '-':
    return n1 - n2;
  case '*':
    return n1 * n2;
  case '/':
    return n1 / n2;
  }
}

int main()
{
  float n1, n2;
  char operation;

  while (1)
  {
    n1 = InputNum("Digite o 1º número: ");
    n2 = InputNum("Digite o 2º número: ");

    do
    {
      operation = InputCharacter("Digite a operação (+ - * /): ");

      if (operation == '+' || operation == '-' || operation == '*' || operation == '/')
        break;

      printf("Caractere inválido!");
    } while (1);

    printf("Resultado: %.2f\n", Calculate(n1, n2, operation));

    printf("\nDigite \"s\" caso queria fazer um novo cálculo: ");
    scanf("%c", &operation);

    if (operation != 's')
      break;
  }

  return 0;
}