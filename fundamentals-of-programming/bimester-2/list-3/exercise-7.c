#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

main()
{
  char frase[1000], letter;
  int i;

  printf("Digite a frase:\n");
  fgets(frase, 1000, stdin);

  printf("Frase inversa substituída:\n");

  for (i = strlen(frase); i >= 0; i--)
  {
    letter = tolower(frase[i]);
    switch (letter)
    {
    case 'b':
    case 'c':
    case 'd':
    case 'f':
    case 'g':
    case 'h':
    case 'j':
    case 'k':
    case 'l':
    case 'm':
    case 'n':
    case 'p':
    case 'q':
    case 'r':
    case 's':
    case 't':
    case 'v':
    case 'w':
    case 'x':
    case 'y':
    case 'z':
      printf("#");
      break;

    default:
      printf("%c", frase[i]);
    }
  }
}