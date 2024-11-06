#include <stdio.h>
#include <stdlib.h>
#define NUMS_LENGTH 5

void InputNums(int nums[], int length)
{
  int i;

  for (i = 0; i < length; i++)
  {
    printf("Digite o %dº número: ", i + 1);
    scanf("%d", &nums[i]);
  }
}

int GetLargest(int nums[], int length)
{
  int i, largest = nums[0];

  for (i = 1; i < length; i++)
    if (nums[i] > largest)
      largest = nums[i];

  return largest;
}

int GetLowest(int nums[], int length)
{
  int i, lowest = nums[0];

  for (i = 1; i < length; i++)
    if (nums[i] < lowest)
      lowest = nums[i];

  return lowest;
}

int main()
{
  int nums[NUMS_LENGTH];

  InputNums(nums, NUMS_LENGTH);

  int largest = GetLargest(nums, NUMS_LENGTH);
  int lowest = GetLowest(nums, NUMS_LENGTH);

  printf("Soma do maior e do menor: %d * %d = %d", lowest, largest, lowest * largest);

  return 0;
}