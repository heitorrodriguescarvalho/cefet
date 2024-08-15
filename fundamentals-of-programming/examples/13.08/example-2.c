#include <stdio.h>
#include <stdlib.h>

main()
{
  int pares[10], nums[10], i;

  for (i = 0; i < 10; i++)
  {
    pares[i] = i * 2 + 2;
  }

  for (i = 0; i < 10; i++)
  {
    nums[i] = i + 10;
  }

  for (i = 0; i < 10; i++)
  {
    printf("Posição %d: %d + %d = %d\n", i, pares[i], nums[i], pares[i] + nums[i]);
  }
}