#include <stdio.h>
#include <stdlib.h>

main() {
  int cliente, quantidade, produto;
  float preco, soma;

  do {
    printf("Digite o código do cliente (0 para parar): ");
    scanf("%d", &cliente);

    if (cliente != 0) {
      do {
        printf("Digite o código do produto: ");
        scanf("%d", &produto);

        if(produto != -1) {
          printf("Digite o preço unitário: R$");
          scanf("%f", &preco);

          printf("Digite a quantidade do produto %d: ", produto);
          scanf("%d", &quantidade);

          soma += preco * quantidade;
        }
      } while (produto != -1);

      printf("Total da compra: R$%.2f\n", soma);

      soma = 0;
    }
  } while(cliente != 0);
}