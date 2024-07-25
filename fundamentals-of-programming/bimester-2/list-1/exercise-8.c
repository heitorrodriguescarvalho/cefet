#include <stdio.h>
#include <stdlib.h>

main() {
  int soma = 0, idade, cont, media = 0;

  for (cont = 1; cont <= 10; cont++) {
    printf("Digite a idade da %dº pessoa: ", cont);
    scanf("%d", &idade);

    if (idade > 18) {
      media++;
      soma += idade;
    }
  }

  if (media == 0) 
    printf("Não há pessoas maiores de 18 anos");
  else 
    printf("Média das idades das pessoas maiores de 18 anos: %f", (float)soma / media);
}