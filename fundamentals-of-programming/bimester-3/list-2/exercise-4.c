#include <stdio.h>
#include <stdlib.h>
#define NUMS_SIZE 4

void InputNums(int nums[][NUMS_SIZE], int length)
{
  int i, j;

  for (i = 0; i < length; i++)
    for (j = 0; j < length; j++)
    {
      printf("Digite o %dº número da %dº coluna: ", j + 1, i + 1);
      scanf("%d", &nums[i][j]);
    }
}

void PrintNums(int nums[][NUMS_SIZE], int length)
{
  int i, j;

  printf("\nMatriz:\n");

  for (i = 0; i < length; i++)
  {
    for (j = 0; j < length; j++)
    {
      printf("%3d", nums[i][j]);
    }

    printf("\n");
  }
}

void PrintMainDiagonal(int nums[][NUMS_SIZE], int length)
{
  int i;

  printf("\nDiagonal principal:\n");

  for (i = 0; i < length; i++)
    printf("%3d", nums[i][i]);
}

void PrintLowestNum(int nums[][NUMS_SIZE], int length)
{
  int i, j, lowest = nums[0][0];

  for (i = 0; i < length; i++)
    for (j = 1; j < length; j++)
      if (nums[i][j] < lowest)
        lowest = nums[i][j];

  printf("\nMenor número: %d", lowest);
}

void PrintLargestNum(int nums[][NUMS_SIZE], int length)
{
  int i, j, largest = nums[0][0];

  for (i = 0; i < length; i++)
    for (j = 1; j < length; j++)
      if (nums[i][j] > largest)
        largest = nums[i][j];

  printf("\nMaior número: %d", largest);
}

int main()
{
  int nums[NUMS_SIZE][NUMS_SIZE];

  InputNums(nums, NUMS_SIZE);

  PrintNums(nums, NUMS_SIZE);

  PrintLowestNum(nums, NUMS_SIZE);

  PrintLargestNum(nums, NUMS_SIZE);

  return 0;
}