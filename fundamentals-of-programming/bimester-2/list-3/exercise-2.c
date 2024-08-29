#include <stdio.h>
#include <stdlib.h>

main()
{
  int nums[15], i, maior, menor, posicaoMaior = 0, posicaoMenor = 0;

  for (i = 0; i < 15; i++)
  {
    printf("Digite o %dº número: ", i + 1);
    scanf("%d", &nums[i]);
  }

  maior = menor = nums[0];
  for (i = 1; i < 15; i++)
  {
    if (nums[i] > maior)
    {
      maior = nums[i];
      posicaoMaior = i;
    }

    if (nums[i] < menor)
    {
      menor = nums[i];
      posicaoMenor = i;
    }
  }

  printf("Maior número: %d\n", maior);
  printf("Posição do maior número: %d\n", posicaoMaior);
  printf("Menor número: %d\n", menor);
  printf("Posição do menor número: %d\n", posicaoMenor);
}