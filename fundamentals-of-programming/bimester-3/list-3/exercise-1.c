#include <stdio.h>
#include <stdlib.h>
#define NUMS_LENGTH 9

void Fill_vector(int nums[], int length)
{
  int i;

  for (i = 0; i < length; i++)
  {
    printf("Digite o %dº número do vetor: ", i + 1);
    scanf("%d", &nums[i]);
  }
}

int Sum(int nums[], int index, int length)
{
  if (index == length - 1)
  {
    return nums[index];
  }

  return nums[index] + Sum(nums, index + 1, length);
}

int main()
{
  int nums[NUMS_LENGTH];

  Fill_vector(nums, NUMS_LENGTH);

  printf("Soma do vetor: %d", Sum(nums, 0, NUMS_LENGTH));

  return 0;
}