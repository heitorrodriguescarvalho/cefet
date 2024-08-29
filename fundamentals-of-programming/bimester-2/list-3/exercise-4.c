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
      cont++;
    }
  }

  printf("Quantidade de consoantes: %d", cont);
}