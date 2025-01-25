#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utils.h"

void RemoveNewlineChar(char string[])
{
  if (string[strlen(string) - 1] == '\n')
    string[strlen(string) - 1] = '\0';
}

int IsNumeric(char string[])
{
  int i;

  for (i = 0; i < (int)strlen(string); i++)
  {
    if (!isdigit(string[i]))
      return 0;
  }

  return 1;
}

void Input_string(char string[], int size)
{
  setbuf(stdin, NULL);
  fgets(string, size, stdin);
  RemoveNewlineChar(string);
}

void Await_enter()
{
  char input;

  printf("\n\nPressione Enter ↵ para voltar...");

  setbuf(stdin, NULL);
  while ((input = getchar()) != '\n')
    ;
}

double Get_max_value(double values[], int size)
{
  double max = values[0];
  int i;

  for (i = 1; i < size; i++)
    if (values[i] > max)
      max = values[i];

  return max;
}

double Get_min_value(double values[], int size)
{
  double min = values[0];
  int i;

  for (i = 1; i < size; i++)
    if (values[i] < min)
      min = values[i];

  return min;
}

int Count_UTF8_chars(char str[])
{
  int i = 0, j = 0;

  while (str[i])
  {
    if ((str[i] & 0xC0) != 0x80)
      j++;
    i++;
  }
  return (j);
}