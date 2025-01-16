#include <stdio.h>
#include <stdlib.h>
#include "student.h"

void Get_student(Student *student, int i)
{
  int grade1, grade2;

  printf("Digite a matrícula do %dº aluno: ", i + 1);
  scanf("%d", &student->id);

  setbuf(stdin, NULL);

  printf("Digite o nome do %dº aluno: ", i + 1);
  fgets(student->name, 50, stdin);

  printf("Digite a 1º nota do %dº aluno: ", i + 1);
  scanf("%d", &grade1);

  printf("Digite a 2º nota do %dº aluno: ", i + 1);
  scanf("%d", &grade2);

  student->average_grade = (float)(grade1 + grade2) / 2;
}

void Print_student(Student student)
{
  printf("\nMatrícula: %d", student.id);
  printf("\nNome: %s", student.name);
  printf("Nota média: %.2f\n", student.average_grade);
}
