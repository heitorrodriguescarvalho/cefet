#include <stdio.h>
#include <stdlib.h>

int main()
{
  int num, sum = 0, count = 0;

  do
  {
    printf("Digite um número (negativo para parar): ");
    scanf("%d", &num);

    if (num % 2 == 0)
    {
      sum += num;
      count++;
    }

    if (num == 0)
      break;
  } while (1);

  printf("Média artimética: %.2f\n", (float)sum / count);
  printf("Quantidade de números digitados: %d", count);

  return 0;
}
