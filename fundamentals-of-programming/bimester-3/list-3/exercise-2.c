#include <stdio.h>
#include <stdlib.h>
#define NUMS_LENGTH 10

void Fill_vector(float nums[], int length)
{
  int i;

  for (i = 0; i < length; i++)
  {
    printf("Digite o %dº número do vetor: ", i + 1);
    scanf("%f", &nums[i]);
  }
}

void Print_vector(float nums[], int length)
{
  int i;

  for (i = 0; i < length; i++)
  {
    printf("%8.2f", nums[i]);
  }
}

void Reverse(float nums[], int index, int length)
{
  int i;

  if (index < length / 2)
  {
    i = nums[index];
    nums[index] = nums[length - 1 - index];
    nums[length - 1 - index] = i;

    Reverse(nums, index + 1, length);
  }
}

int main()
{
  float nums[NUMS_LENGTH];

  Fill_vector(nums, NUMS_LENGTH);

  printf("Vetor invetido: ");
  Reverse(nums, 0, NUMS_LENGTH);
  Print_vector(nums, NUMS_LENGTH);

  return 0;
}