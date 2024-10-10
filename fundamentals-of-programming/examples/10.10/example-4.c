#include <stdio.h>
#include <stdlib.h>

void FillArray(int array[4][4])
{
  int i, j;

  for (i = 0; i < 4; i++)
    for (j = 0; j < 4; j++)
    {
      printf("Digite o %dº valor da %dº coluna: ", j + 1, i + 1);
      scanf("%d", &array[i][j]);
    }
}

void PrintArray(int array[4][4])
{
  int i, j;

  printf("\nMatriz:\n");

  for (i = 0; i < 4; i++)
  {
    for (j = 0; j < 4; j++)
      printf("%3d", array[i][j]);

    printf("\n");
  }
}

int GetLargest(int array[4][4])
{
  int maior = array[0][0], i, j;

  for (i = 0; i < 4; i++)
    for (j = 0; j < 4; j++)
      if (array[i][j] > maior)
        maior = array[i][j];

  return maior;
}

void PrintSecondaryDiagonal(int array[4][4])
{
  int i;

  printf("\Diagonal Secundária: ");

  for (i = 3; i >= 0; i--)
    printf("%d ", array[3 - i][i]);
}

main()
{
  int array[4][4];

  FillArray(array);

  PrintArray(array);

  printf("Maior número: %d\n", GetLargest(array));

  PrintSecondaryDiagonal(array);
}