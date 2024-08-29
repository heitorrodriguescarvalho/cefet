#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

main()
{
  char frase[1000], letter;
  int i, cont = 0;

  printf("Digite a frase:\n");
  fgets(frase, 1000, stdin);

  for (i = 0; i < strlen(frase); i++)
  {
    letter = tolower(frase[i]);
    if (
        letter == 'a' ||
        letter == 'e' ||
        letter == 'i' ||
        letter == 'o' ||
        letter == 'u')
      cont++;
  }

  printf("Quantidade de vogais: %d", cont);
}