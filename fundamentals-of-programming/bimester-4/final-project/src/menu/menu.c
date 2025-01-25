#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdarg.h>

// Exceptions menus
void Message(char message[])
{
  printf("\e[1;1H\e[2J");
  fflush(stdout);
  printf(message);
  fflush(stdout);
  sleep(2);
  printf("\e[1;1H\e[2J");
  fflush(stdout);
}

int Try_again(char message[])
{
  int input;

  while (1)
  {
    system("clear");

    printf("%s\n\n1. Tentar novamente\n2. Voltar\n\nEscolha uma opção: ", message);
    scanf("%d", &input);

    switch (input)
    {
    case 1:
      return 1;
      break;
    case 2:
      return 0;
      break;
    default:
      Message("Entrada Inválida...");
      break;
    }
  }
}

int Confirm(char message[], ...)
{
  int input;
  char buffer[1024];
  va_list args;

  va_start(args, message);

  vsnprintf(buffer, sizeof(buffer), message, args);

  va_end(args);

  while (1)
  {
    system("clear");

    printf("%s\n\n1. Confirmar\n2. Cancelar\n\nEscolha uma opção: ", buffer);
    scanf("%d", &input);

    switch (input)
    {
    case 1:
      return 1;
      break;
    case 2:
      return 0;
      break;
    default:
      Message("Entrada Inválida...");
      break;
    }
  }
}