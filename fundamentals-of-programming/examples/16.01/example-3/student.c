#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "student.h"

void Get_student(Student *student, int i)
{
  int j;

  printf("Digite a matrícula do %dº aluno: ", i + 1);
  scanf("%d", &student->id);

  for (j = 0; j < 3; j++)
  {
    printf("Digite a %dº nota do %dº aluno: ", j + 1, i + 1);
    scanf("%f", &student->grades[j]);
  }
}

float Get_student_average_grade(Student student)
{
  int i;
  float average_grade = 0;

  for (i = 0; i < 3; i++)
  {
    average_grade += student.grades[i];
  }

  average_grade /= 3;

  return average_grade;
}

int Get_largest_first_grade_student(Student students[])
{
  int i, largest_first_grade_student = 0;

  for (i = 0; i < 5; i++)
    if (students[i].grades[0] > students[largest_first_grade_student].grades[0])
      largest_first_grade_student = i;

  return largest_first_grade_student;
}

int Get_largest_average_grade_student(Student students[])
{
  int i, largest_average_grade_student = 0;
  float largest_average_grade = -INFINITY;

  for (i = 0; i < 5; i++)
  {
    float average_grade = Get_student_average_grade(students[i]);

    if (average_grade > largest_average_grade)
    {
      largest_average_grade_student = i;
      largest_average_grade = average_grade;
    }
  }

  return largest_average_grade_student;
}

int Get_lowest_average_grade_student(Student students[])
{
  int i, lowest_average_grade_student = 0;
  float lowest_average_grade = INFINITY;

  for (i = 0; i < 5; i++)
  {
    float average_grade = Get_student_average_grade(students[i]);

    if (average_grade < lowest_average_grade)
    {
      lowest_average_grade_student = i;
      lowest_average_grade = average_grade;
    }
  }

  return lowest_average_grade_student;
}

void Print_students_infos(Student students[], int largest_first_grade_student, int largest_average_grade_student, int lowest_average_grade_student)
{
  int i;

  printf("\n\nAluno com maior nota da primeira prova:");
  printf("\n\tId: %d", students[largest_first_grade_student].id);
  printf("\n\tNota: %.2f", students[largest_first_grade_student].grades[0]);

  printf("\n\nAluno com maior média geral:");
  printf("\n\tId: %d", students[largest_average_grade_student].id);
  printf("\n\tNota média: %.2f", Get_student_average_grade(students[largest_average_grade_student]));

  printf("\n\nAluno com menor média geral:");
  printf("\n\tId: %d", students[lowest_average_grade_student].id);
  printf("\n\tNota média: %.2f", Get_student_average_grade(students[lowest_average_grade_student]));

  printf("\n\nSituação dos alunos:");
  for (i = 0; i < 5; i++)
  {
    printf("\n\t%d: ", students[i].id);

    if (Get_student_average_grade(students[i]) < 6)
      printf("Reprovado");
    else
      printf("Aprovado");
  }
}