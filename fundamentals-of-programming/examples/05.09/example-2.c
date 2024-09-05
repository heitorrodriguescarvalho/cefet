#include <stdio.h>
#include <stdlib.h>

main()
{
  int nums[3][2], i, j, cont = 0, sum = 0;

  for (i = 0; i < 3; i++)
  {
    for (j = 0; j < 2; j++)
    {
      printf("Digite o %dº número da %dº linha: ", j + 1, i + 1);
      scanf("%d", &nums[i][j]);
    }
  }

  for (i = 0; i < 3; i++)
  {
    for (j = 0; j < 2; j++)
    {
      if (nums[i][j] % 2 == 1)
      {
        sum += nums[i][j];
        cont++;
      }
    }
  }

  printf("Média: %.2f", (float)sum / cont);
}