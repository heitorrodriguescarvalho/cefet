#include <stdio.h>
#include <stdlib.h>

main()
{
  int nums[10], i, j;

  for (i = 0; i < 10; i++)
  {
    printf("Digite o %dº número: ", i + 1);
    scanf("%d", &nums[i]);

    for (j = 0; j < i; j++)
    {
      if (nums[i] == nums[j])
      {
        printf("Valor inválido\n");
        i--;
      }
    }
  }

  printf("Vetor: ");
  for (i = 0; i < 10; i++)
  {
    printf("%d ", nums[i]);
  }
}