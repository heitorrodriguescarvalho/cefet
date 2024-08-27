#include <stdio.h>
#include <stdlib.h>
#include <string.h>

main()
{
  char word[100], l1, l2, lowercase;
  int i, cont = 0;

  printf("Escreva uma frase: ");
  fgets(word, 100, stdin);

  printf("Letra procurada: ");
  scanf("%c", &l1);

  printf("Letra substituta: ");
  scanf(" %c", &l2);

  for (i = 0; i < strlen(word); i++)
  {
    if (word[i] == l1)
      word[i] = l2;
  }

  printf("String subsituída: %s", word);
}