#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NUM_STUDENTS 40
#define NUM_GRADES 2

void InputNames(char names[][50], int size)
{
  int i;

  for (i = 0; i < size; i++)
  {
    printf("Digite o nome do %dº aluno: ", i + 1);
    fgets(names[i], 50, stdin);

    if (strlen(names[i]) > 0 && names[i][strlen(names[i]) - 1] == '\n')
    {
      names[i][strlen(names[i]) - 1] = '\0';
    }
  }
}

void InputGrades(float grades[][NUM_GRADES], int amountOfStudents, int amountOfGrades)
{
  int i, j;

  for (i = 0; i < amountOfStudents; i++)
    for (j = 0; j < amountOfGrades; j++)
    {
      do
      {
        printf("Digite a %dº nota do %dº aluno: ", j + 1, i + 1);
        scanf("%f", &grades[i][j]);
      } while (grades[i][j] > 10 || grades[i][j] < 0);
    }
}

void CalcAndPrintAverageGrade(char names[][50], float grades[][NUM_GRADES], float averageGrades[], int amountOfGrades, int amountOfStudents)
{
  int i, j;

  printf("Notas médias:\n");

  for (i = 0; i < amountOfStudents; i++)
  {
    averageGrades[i] = 0;

    for (j = 0; j < amountOfGrades; j++)
    {
      averageGrades[i] += grades[i][j];
    }

    averageGrades[i] /= amountOfGrades;

    printf("\t%s: %.2f\n", names[i], averageGrades[i]);
  }
}

void PrintLargestAverageGrade(float averagesGrades[], int size)
{
  int i;
  float largest = averagesGrades[0];

  for (i = 1; i < size; i++)
    if (averagesGrades[i] > largest)
      largest = averagesGrades[i];

  printf("Maior nota média: %.2f\n", largest);
}

void PrintLowestAverageGrade(float averagesGrades[], int size)
{
  int i;
  float lowest = averagesGrades[0];

  for (i = 1; i < size; i++)
    if (averagesGrades[i] < lowest)
      lowest = averagesGrades[i];

  printf("Menor nota média: %.2f\n", lowest);
}

void CalcStudentsStatus(float averageGrades[], int studentsStatus[], int size)
{
  int i;

  studentsStatus[0] = 0;
  studentsStatus[1] = 0;
  studentsStatus[2] = 0;

  for (i = 0; i < size; i++)
  {
    if (averageGrades[i] < 4)
      studentsStatus[0]++;
    else if (averageGrades[i] < 6)
      studentsStatus[1]++;
    else
      studentsStatus[2]++;
  }
}

void PrintListOfStudentsInRecovery(char names[][50], float averageGrades[], int amountOfStudents)
{
  int i;

  printf("Alunos em recuperação:\n");

  for (i = 0; i < amountOfStudents; i++)
  {
    if (averageGrades[i] < 6 && averageGrades[i] >= 4)
      printf("\t%s: %.2f\n", names[i], averageGrades[i]);
  }
}

main()
{
  char names[NUM_STUDENTS][50];
  float grades[NUM_STUDENTS][NUM_GRADES], averageGrades[NUM_STUDENTS];
  int studentsStatus[3];

  InputNames(names, NUM_STUDENTS);
  InputGrades(grades, NUM_STUDENTS, NUM_GRADES);

  CalcAndPrintAverageGrade(names, grades, averageGrades, NUM_GRADES, NUM_STUDENTS);

  PrintLargestAverageGrade(averageGrades, NUM_STUDENTS);
  PrintLowestAverageGrade(averageGrades, NUM_STUDENTS);

  CalcStudentsStatus(averageGrades, studentsStatus, NUM_STUDENTS);

  printf("Alunos aprovados: %d\n", studentsStatus[2]);
  printf("Alunos em recuperação: %d\n", studentsStatus[1]);
  printf("Alunos reprovados: %d\n", studentsStatus[0]);

  PrintListOfStudentsInRecovery(names, averageGrades, NUM_STUDENTS);
}