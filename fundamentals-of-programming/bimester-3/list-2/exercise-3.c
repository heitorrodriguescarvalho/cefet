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

float CalcGrades(float n1, float n2, float n3, char averageType)
{
  if (averageType == 'a')
  {
    return (n1 + n2 + n3) / 3;
  }
  else if (averageType == 'p')
  {
    return (n1 * 5 + n2 * 3 + n3 * 2) / 10;
  }
}

int main()
{
  float n1, n2, n3;
  char averageType;

  n1 = InputNum("Digite a 1º nota: ");
  n2 = InputNum("Digite a 2º nota: ");
  n3 = InputNum("Digite a 3º nota: ");

  do
  {
    averageType = InputCharacter("Digite \"a\" para média aritmética e \"p\" para ponderada: ");

    if (averageType == 'a' || averageType == 'p')
      break;

    printf("Caractere inválido!");
  } while (1);

  printf("Nota obtida: %.2f", CalcGrades(n1, n2, n3, averageType));

  return 0;
}