#include <stdio.h>
#include <stdlib.h>

int main()
{
  int num, sum = 0, largest = -1, count = 0;

  do
  {
    printf("Digite um número (negativo para parar): ");
    scanf("%d", &num);

    if (num >= 0)
    {
      sum += num;
      count++;

      if (num > largest)
        largest = num;
    }
    else
      break;
  } while (1);

  printf("Média artimética: %.2f\n", (float)sum / count);
  printf("Maior número: %d", largest);

  return 0;
}
