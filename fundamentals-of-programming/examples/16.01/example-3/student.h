typedef struct
{
  int id;
  float grades[3];
} Student;

void Get_student(Student *, int);
int Get_largest_first_grade_student(Student[]);
int Get_largest_average_grade_student(Student[]);
int Get_lowest_average_grade_student(Student[]);
void Print_students_infos(Student[], int, int, int);