#include <stdlib.h>
#include <stdio.h>
#include "people.h"

int main()
{
  Person people[5];

  GetPeople(people);
  GetOlderPerson(people);
  GetYoungestPerson(people);
  SortPeople(people);
  PrintPeople(people);

  return 0;
}
