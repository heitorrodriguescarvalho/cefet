#include <stdio.h>
#include <stdlib.h>

main() {
  int num1, num2, num3, num4;

  printf("Digite quatro números:\n");
  scanf("%d %d %d %d", &num1, &num2, &num3, &num4);

  printf("O número %d é múltiplo de ", num1);
  if (num1 % 3 == 0) printf("3 ");
  if (num1 % 5 == 0) printf("5 ");
  if (num1 % 7 == 0) printf("7 ");
  if (num1 % 3 != 0 && num1 % 5 != 0 && num1 % 7 != 0) printf("nenhum número.\n");
  else printf("\n");

  printf("O número %d é múltiplo de ", num2);
  if (num2 % 3 == 0) printf("3 ");
  if (num2 % 5 == 0) printf("5 ");
  if (num2 % 7 == 0) printf("7 ");
  if (num2 % 3 != 0 && num2 % 5 != 0 && num2 % 7 != 0) printf("nenhum número.\n");
  else printf("\n");

  printf("O número %d é múltiplo de ", num3);
  if (num3 % 3 == 0) printf("3 ");
  if (num3 % 5 == 0) printf("5 ");
  if (num3 % 7 == 0) printf("7 ");
  if (num3 % 3 != 0 && num3 % 5 != 0 && num3 % 7 != 0) printf("nenhum número.\n");
  else printf("\n");

  printf("O número %d é múltiplo de ", num4);
  if (num4 % 3 == 0) printf("3 ");
  if (num4 % 5 == 0) printf("5 ");
  if (num4 % 7 == 0) printf("7 ");
  if (num4 % 3 != 0 && num4 % 5 != 0 && num4 % 7 != 0) printf("nenhum número.\n");
  else printf("\n");
}