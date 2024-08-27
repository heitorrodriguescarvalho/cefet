#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

main()
{
  char word1[100], word2[100], lowercase;
  int i;

  printf("Escreva uma palavra: ");
  fgets(word1, 100, stdin);

  printf("Escreva outra palavra: ");
  fgets(word2, 100, stdin);

  printf("Primeira string: ");

  for (i = strlen(word1); i >= 0; i--)
  {
    lowercase = tolower(word1[i]);
    if (lowercase == 'a')
    {
      word1[i] = '*';
    }

    printf("%c", word1[i]);
  }

  printf("\nSegunda string: ");

  for (i = strlen(word2); i >= 0; i--)
  {
    lowercase = tolower(word2[i]);
    if (lowercase == 'a')
    {
      word2[i] = '*';
    }

    printf("%c", word2[i]);
  }
}