#include <stdio.h>
#include <stdlib.h>

void FillVetor(int nums[], int size)
{
  int i = 0;

  for (i = 0; i < size; i++)
    scanf("%d", &nums[i]);
}

int GetLargest(int nums[], int size)
{
  int i, largest = nums[0];

  for (i = 0; i < size; i++)
    if (nums[i] > largest)
      largest = nums[i];

  return largest;
}

main()
{
  int nums[10];

  printf("Digite dez números:\n");
  FillVetor(nums, 10);

  printf("Maior valor: %d", GetLargest(nums, 10));
}