#include <stdio.h>
#include <stdlib.h>

main()
{
  int nums[3][3], i, j, sum = 0;

  for (i = 0; i < 3; i++)
  {
    for (j = 0; j < 3; j++)
    {
      printf("Digite o %dº número da %dº linha: ", j + 1, i + 1);
      scanf("%d", &nums[i][j]);
    }
  }

  for (i = 0; i < 3; i++)
  {
    sum += nums[i][i];
  }

  printf("Média da diagonal principal: %.2f", (float)sum / 3);
}