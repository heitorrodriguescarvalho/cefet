#include <stdio.h>
#include <stdlib.h>

main() {
  int man1, man2, woman1, woman2;

  printf("Digite a idade dos 2 homens:\n");
  scanf("%d %d", &man1, &man2);

  printf("Digite a idade das 2 mulheres:\n");
  scanf("%d %d", &woman1, &woman2);
  
  if (man1 > man2) {
    if (woman1 < woman2) {
      printf("Idade do homem mais velho + Idade da mulher mais nova: %d\n", man1 + woman1);
      printf("Idade do homem mais novo * Idade da mulher mais velha = %d\n", man2 * woman2);
    } else {
      printf("Idade do homem mais velho + Idade da mulher mais nova: %d\n", man1 + woman2);
      printf("Idade do homem mais novo * Idade da mulher mais velha = %d\n", man2 * woman1);
    }
  } else {
    if (woman1 < woman2) {
      printf("Idade do homem mais velho + Idade da mulher mais nova: %d\n", man2 + woman1);
      printf("Idade do homem mais novo * Idade da mulher mais velha = %d\n", man1 * woman2);
    } else {
      printf("Idade do homem mais velho + Idade da mulher mais nova: %d\n", man2 + woman2);
      printf("Idade do homem mais novo * Idade da mulher mais velha = %d\n", man1 * woman1);
    }
  }
}