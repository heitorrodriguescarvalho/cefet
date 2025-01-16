#include <stdio.h>
#include <stdlib.h>
#include "student.h"

int main()
{
  Student students[5];
  int i;

  for (i = 0; i < 5; i++)
  {
    Get_student(&students[i], i);
  }

  int largest_first_grade_student = Get_largest_first_grade_student(students),
      largest_average_grade_student = Get_largest_average_grade_student(students),
      lowest_average_grade_student = Get_lowest_average_grade_student(students);

  Print_students_infos(students, largest_first_grade_student, largest_average_grade_student, lowest_average_grade_student);

  return 0;
}