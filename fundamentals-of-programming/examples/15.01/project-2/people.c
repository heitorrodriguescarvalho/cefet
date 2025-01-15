#include <stdlib.h>
#include <stdio.h>
#include "people.h"

void GetPeople(Person person[])
{
  int age, x;
  for (x = 0; x < 5; x++)
  {
    fflush(stdin);
    printf("Digite o nome da pessoa %d\n", x + 1);
    scanf("%s", &person[x].name);
    fflush(stdin);
    printf("Digite o cpf da pessoa %d\n", x + 1);
    scanf("%lf", &person[x].cpf);
    printf("Digite o ano de nascimento da pessoa %d\n", x + 1);
    scanf("%d", &age);
    person[x].year = 2025 - age;
  }
}

void GetOlderPerson(Person person[])
{
  int older = 0, index;
  for (int x = 0; x < 5; x++)
  {
    if (older < person[x].year)
    {
      older = person[x].year;
      index = x;
    }
  }
  printf("A pessoa mais Velha eh: %s\n", person[index].name);
}

void GetYoungestPerson(Person person[])
{
  int younger = 999999, index, x;

  for (x = 0; x < 5; x++)
  {
    if (younger > person[x].year)
    {
      younger = person[x].year;
      index = x;
    }
  }

  printf("A pessoa mais Nova eh: %s\n", person[index].name);
}

void SortPeople(Person person[])
{
  Person aux;
  int i, j;
  for (j = 0; j < 4; j++)
    for (i = 0; i < 4; i++)
      if (person[i].year > person[i + 1].year)
      {
        aux = person[i];
        person[i] = person[i + 1];
        person[i + 1] = aux;
      }
}

void PrintPeople(Person person[])
{
  for (int x = 0; x < 5; x++)
    printf("Dados da pessoa %d\n Nome: %s - CPF: %.0lf - Idade: %d\n\n", x + 1, person[x].name, person[x].cpf, person[x].year);
}
