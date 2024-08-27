#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

main()
{
  char word[100], letter, lowercase;
  int i, cont = 0;

  printf("Escreva uma palavra: ");
  fgets(word, 100, stdin);

  printf("Escreva o caractere que substitui as vogais: ");
  scanf("%c", &letter);

  for (i = strlen(word); i >= 0; i--)
  {
    lowercase = tolower(word[i]);
    if (lowercase == 'a' || lowercase == 'e' || lowercase == 'i' || lowercase == 'o' || lowercase == 'u')
    {
      cont++;
      word[i] = letter;
    }
  }

  printf("Total de vogais: %d\n", cont);
  printf("String subsituída: %s", word);
}