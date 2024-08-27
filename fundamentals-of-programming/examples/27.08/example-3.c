#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

main()
{
  char word[100], lowercase;
  int i;

  printf("Escreva uma palavra: ");
  fgets(word, 100, stdin);

  for (i = 0; i < strlen(word); i++)
  {
    lowercase = tolower(word[i]);
    if (lowercase != 'a' && lowercase != 'e' && lowercase != 'i' && lowercase != 'o' && lowercase != 'u')
      printf("%c", word[i]);
  }
}