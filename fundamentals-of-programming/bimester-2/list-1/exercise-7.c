#include <stdio.h>
#include <stdlib.h>
#include <math.h>

main() {
  int n1, n2, n3, cont, menor = INFINITY, meio, maior = -INFINITY;

  printf("Digite três números:\n");
  scanf("%d %d %d", &n1, &n2, &n3);

  if (n1 < menor)
    menor = n1;

  if (n2 < menor)
    menor = n2;

  if (n3 < menor)
    menor = n3;

  if (n1 > maior)
    maior = n1;

  if (n2 > maior)
    maior = n2;

  if (n3 > maior)
    maior = n3;

  if (n1 != maior && n1 != menor)
    meio = n1;

  if (n2 != maior && n2 != menor)
    meio = n2;

  if (n3 != maior && n3 != menor)
    meio = n3;

  printf("Ordem crescente: %d %d %d\n", menor, meio, maior);
  printf("Ordem decrescente: %d %d %d", maior, meio, menor);
}