#include <stdio.h>
#include <stdlib.h>

int Largest(int nums[])
{
  int i, maior = nums[0];

  for (i = 0; i < 3; i++)
    if (nums[i] > maior)
      maior = nums[i];

  return maior;
}

int Lowest(int nums[])
{
  int i, menor = nums[0];

  for (i = 0; i < 3; i++)
    if (nums[i] < menor)
      menor = nums[i];

  return menor;
}

void Print(int maior, int menor)
{
  printf("Maior: %d\nMenor: %d", maior, menor);
}

main()
{
  int nums[3], i;

  for (i = 0; i < 3; i++)
  {
    printf("Digite o %dº número: ", i + 1);
    scanf("%d", &nums[i]);
  }

  int maior = Largest(nums), menor = Lowest(nums);

  Print(maior, menor);
}