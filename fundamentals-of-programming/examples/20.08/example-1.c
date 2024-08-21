#include <stdio.h>
#include <stdlib.h>
#include <string.h>

main()
{
  char text[80];
  int i, cont = 0;

  fgets(text, sizeof(text), stdin);

  int size = strlen(text);

  for (i = 0; i < size; i++)
  {
    if (text[i] == 'a')
    {
      cont++;
      text[i] = 'b';
    }
  }

  printf("Caracteres modificados: %d\n Resultado: %s", cont, text);
}