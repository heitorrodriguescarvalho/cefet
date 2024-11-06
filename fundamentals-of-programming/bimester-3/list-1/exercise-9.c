#include <stdio.h>
#include <stdlib.h>
#define NUMS_LENGTH 10

void InputNums(int nums[], int length)
{
  int i;

  for (i = 0; i < length; i++)
  {
    printf("Digite o %dº número: ", i + 1);
    scanf("%d", &nums[i]);
  }
}

void ReplaceNums(int nums[], int replaced[], int length, int select, int replace)
{
  int i;

  for (i = 0; i < length; i++)
    if (nums[i] == select)
      replaced[i] = replace;
    else
      replaced[i] = nums[i];
}

void PrintNums(int nums[], int length)
{
  int i;

  for (i = 0; i < length; i++)
    if (nums[i] >= 0)
      printf("%3d ", nums[i]);
}

int main()
{
  int nums[NUMS_LENGTH], numsReplaced[NUMS_LENGTH];

  InputNums(nums, NUMS_LENGTH);

  ReplaceNums(nums, numsReplaced, NUMS_LENGTH, 0, 1);

  printf("\nVetor original: ");
  PrintNums(nums, NUMS_LENGTH);

  printf("\nVetor com substituições: ");
  PrintNums(numsReplaced, NUMS_LENGTH);

  return 0;
}