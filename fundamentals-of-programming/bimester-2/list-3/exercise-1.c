#include <stdio.h>
#include <stdlib.h>
#include <string.h>

main()
{
  char produtos[5][100];
  float precos[5], soma = 0;
  int i, c, cont = 0;

  for (i = 0; i < 5; i++)
  {
    printf("Nome do %dº produto: ", i + 1);
    fgets(produtos[i], 100, stdin);
    printf("Preço do %dº produto: ", i + 1);
    scanf("%f", &precos[i]);

    // Limpa o buffer
    while ((c = getchar()) != '\n' && c != EOF)
      ;
  }

  for (i = 0; i < 5; i++)
  {
    if (precos[i] < 50)
      cont++;
  }

  printf("Quantidade de produtos de preço inferior a R$50,00: %d\n", cont);

  printf("Produtos de preço entre R$50,00 e R$100,00: ");

  for (i = 0; i < 5; i++)
  {
    if (precos[i] > 50 && precos[i] < 100)
      printf("%s\t", produtos[i]);
  }

  cont = 0;

  for (i = 0; i < 5; i++)
  {
    if (precos[i] > 100)
    {
      soma += precos[i];
      cont++;
    }
  }

  printf("\nMédia do preço dos produtos de preço maior que R$100,00: %.2f", soma / cont);
}