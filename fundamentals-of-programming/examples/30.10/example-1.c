#include <stdio.h>
#include <stdlib.h>
#define NUM_STUDENTS 3
#define GRADES_PER_STUDENT 2

void GetGrades(float grades[][GRADES_PER_STUDENT], int size1, int size2)
{
  int i, j;

  for (i = 0; i < size1; i++)
  {
    printf("Notas do %dº aluno:\n", i + 1);

    for (j = 0; j < size2; j++)
    {
      do
      {
        printf("\tDigite a %dº nota: ", j + 1);
        scanf("%f", &grades[i][j]);
      } while (grades[i][j] < 0 || grades[i][j] > 10);
    }
  }
}

void CalcAverageGrades(float grades[][GRADES_PER_STUDENT], int gradesSize1, int gradesSize2, float averageGrades[], int averageGradesSize)
{
  int i, j;

  for (i = 0; i < gradesSize1; i++)
  {
    averageGrades[i] = 0;

    for (j = 0; j < gradesSize2; j++)
    {
      averageGrades[i] += grades[i][j];
    }

    averageGrades[i] /= gradesSize2;
  }
}

float CalcClassAverageGrade(float averageGrades[], int size)
{
  int i;
  float count = 0;

  for (i = 0; i < size; i++)
  {
    count += averageGrades[i];
  }

  count /= size;

  return count;
}

int CountBestGradesStudents(float averageGrades[], int size, float classAverageGrade)
{
  int i, count = 0;

  for (i = 0; i < size; i++)
    if (averageGrades[i] > classAverageGrade)
      count++;

  return count;
}

main()
{
  float grades[NUM_STUDENTS][GRADES_PER_STUDENT];
  GetGrades(grades, NUM_STUDENTS, GRADES_PER_STUDENT);

  float averageGrades[NUM_STUDENTS];
  CalcAverageGrades(grades, NUM_STUDENTS, GRADES_PER_STUDENT, averageGrades, NUM_STUDENTS);

  float classAverageGrade = CalcClassAverageGrade(averageGrades, NUM_STUDENTS);

  int countOfBestGradesStudents = CountBestGradesStudents(averageGrades, NUM_STUDENTS, classAverageGrade);

  printf("Média geral da turma: %.2f\n", classAverageGrade);
  printf("Alunos com nota acima da média: %d", countOfBestGradesStudents);
}