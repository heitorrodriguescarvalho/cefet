#include <stdio.h>
#include <stdlib.h>
#define NUMS_LENGTH 3

void InputNums(int nums[], int length)
{
  int i;

  for (i = 0; i < length; i++)
  {
    printf("Digite o %dº número: ", i + 1);
    scanf("%d", &nums[i]);
  }
}

void AscendingOrder(int nums[], int length)
{
  int i, j, k, lowestValue;

  for (i = 0; i < length; i++)
  {
    lowestValue = nums[i];

    for (j = i; j < length; j++)
      if (nums[j] < lowestValue)
      {
        k = nums[i];
        nums[i] = nums[j];
        nums[j] = k;
      }
  }

  printf("\nOrdem crescente: ");

  for (i = 0; i < length; i++)
  {
    printf("%d ", nums[i]);
  }
}

void DescendingOrder(int nums[], int length)
{
  int i, j, k, largestValue;

  for (i = 0; i < length; i++)
  {
    largestValue = nums[i];

    for (j = i; j < length; j++)
      if (nums[j] > largestValue)
      {
        k = nums[i];
        nums[i] = nums[j];
        nums[j] = k;
      }
  }

  printf("\nOrdem decrescente: ");

  for (i = 0; i < length; i++)
  {
    printf("%d ", nums[i]);
  }
}

int main()
{
  int nums[NUMS_LENGTH];

  InputNums(nums, NUMS_LENGTH);

  AscendingOrder(nums, NUMS_LENGTH);
  DescendingOrder(nums, NUMS_LENGTH);

  return 0;
}