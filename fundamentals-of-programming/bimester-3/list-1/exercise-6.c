#include <stdio.h>
#include <stdlib.h>

int main()
{
  int cigarettes;
  float years, price;

  printf("Digite o número de anos fumando: ");
  scanf("%f", &years);

  printf("Digite o número de cigarros fumados por dia: ");
  scanf("%d", &cigarettes);

  printf("Digite o preço de uma carteira de cigarros: ");
  scanf("%f", &price);

  printf("Total gasto em cigarros: R$%.2f", (float)cigarettes / 20 * price * years * 365);

  return 0;
}