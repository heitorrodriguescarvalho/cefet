#include <stdio.h>
#include <stdlib.h>
#include <math.h>

main() {
  float num1, num2, num3;

  printf("Digite três valores:\n");
  scanf("%f %f %f", &num1, &num2, &num3);

  if (num1 <= num2 && num1 <= num3) {
    printf("%f ", num1);
    num1 = INFINITY;
  } else if (num2 <= num1 && num2 <= num3) {
    printf("%f ", num2);
    num2 = INFINITY;
  } else if (num3 <= num1 && num3 <= num2) {
    printf("%f ", num3);
    num3 = INFINITY;
  }

  if (num1 <= num2 && num1 <= num3) {
    printf("%f ", num1);
    num1 = INFINITY;
  } else if (num2 <= num1 && num2 <= num3) {
    printf("%f ", num2);
    num2 = INFINITY;
  } else if (num3 <= num1 && num3 <= num2) {
    printf("%f ", num3);
    num3 = INFINITY;
  }

  if (num1 <= num2 && num1 <= num3) {
    printf("%f ", num1);
    num1 = INFINITY;
  } else if (num2 <= num1 && num2 <= num3) {
    printf("%f ", num2);
    num2 = INFINITY;
  } else if (num3 <= num1 && num3 <= num2) {
    printf("%f ", num3);
    num3 = INFINITY;
  }
}