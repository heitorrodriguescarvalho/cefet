#include <stdio.h>
#include <stdlib.h>
#include <math.h>

main() {
  int horas;

  printf("Digite as horas: ");
  scanf("%d", &horas);

  printf("Já se passaram pelo menos %d minutos.", horas * 60);
}