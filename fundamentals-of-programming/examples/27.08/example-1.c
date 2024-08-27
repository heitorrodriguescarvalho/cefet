#include <stdio.h>
#include <stdlib.h>
#include <string.h>

main()
{
  char str1[1000], str2[1000];
  int i, size, equals = 1;

  printf("Digite as duas strings:\n");
  fgets(str1, 1000, stdin);
  fgets(str2, 1000, stdin);

  if (strlen(str1) >= strlen(str2))
    size = strlen(str1);
  else
    size = strlen(str2);

  for (i = 0; i < size; i++)
  {
    if (str1[i] != str2[i])
      equals = 0;
  }

  if (equals == 0)
  {
    printf("As strings são diferentes");
  }
  else
  {
    printf("As strings são iguais");
  }
}