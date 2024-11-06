#include <stdio.h>
#include <stdlib.h>
#define NUMS_LENGTH 20

void InputNums(int nums[], int length)
{
  int i;

  for (i = 0; i < length; i++)
  {
    printf("Digite o %dº número: ", i + 1);
    scanf("%d", &nums[i]);
  }
}

void PrintPositiveNums(int nums[], int length)
{
  int i;

  printf("Números positivos: ");

  for (i = 0; i < length; i++)
    if (nums[i] >= 0)
      printf("%3d ", nums[i]);
}

int main()
{
  int nums[NUMS_LENGTH];

  InputNums(nums, NUMS_LENGTH);
  PrintPositiveNums(nums, NUMS_LENGTH);

  return 0;
}