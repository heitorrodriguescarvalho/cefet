#include <stdio.h>
#include <stdlib.h>

main() {
  int cliente, produto, quant;
  float preco, soma = 0;

  printf("Digite o código do cliente: ");
  scanf("%d", &cliente);

  while(cliente != 0) {
    printf("Digite o código do produto: ");
    scanf("%d", &produto);

    while (produto != -1) {
      printf("Digite o preço do produto: R$");
      scanf("%f", &preco);

      printf("Digite a quantidade de produtos: ");
      scanf("%d", &quant);

      soma += preco * quant;

      printf("Digite o código do produto: ");
      scanf("%d", &produto);
    }

    printf("Total da compra: R$%.2f\n", soma);

    printf("Digite o código do cliente: ");
    scanf("%d", &cliente);

    soma = 0;
  }
}