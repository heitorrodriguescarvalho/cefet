#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

main()
{
  char frase[1000];
  int i;

  printf("Digite a frase:\n");
  fgets(frase, 1000, stdin);

  printf("Frase inversa:\n");

  for (i = strlen(frase); i >= 0; i--)
  {
    printf("%c", frase[i]);
  }
}