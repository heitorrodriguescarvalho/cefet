#include <stdio.h>
#include <stdlib.h>
#include "student.h"

int main()
{
  Student students[5];
  int i;

  for (i = 0; i < 5; i++)
    Get_student(&students[i], i);

  for (i = 0; i < 5; i++)
    Print_student(students[i]);

  return 0;
}