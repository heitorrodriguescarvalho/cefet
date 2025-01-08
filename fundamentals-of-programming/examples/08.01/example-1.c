#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
  char name[50];
  int id;
  char description[200];
} Student;

void GetStudentValues(Student *student)
{
  printf("Nome: ");
  fgets(student->name, 50, stdin);

  printf("Id: ");
  scanf("%d", &student->id);

  setbuf(stdin, NULL);

  printf("Description: ");
  fgets(student->description, 200, stdin);
}

int main()
{
  Student student;

  GetStudentValues(&student);

  printf("\nName: %s", student.name);
  printf("Id: %d\n", student.id);
  printf("description: %s", student.description);

  return 0;
}