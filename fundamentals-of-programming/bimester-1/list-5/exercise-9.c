#include <stdio.h>
#include <stdlib.h>

main() {
  float num1, num2, num3, num4, num5, higher1, higher2;

  printf("Digite 5 valores:\n");
  scanf("%f %f %f %f %f", &num1, &num2, &num3, &num4, &num5);

  if (num1 > num2) {
      higher1 = num1;
      higher2 = num2;
  } else {
      higher1 = num2;
      higher2 = num1;
  }

  if (num3 > higher1) {
      higher2 = higher1;
      higher1 = num3;
  } else if (num3 > higher2) {
      higher2 = num3;
  }

  if (num4 > higher1) {
      higher2 = higher1;
      higher1 = num4;
  } else if (num4 > higher2) {
      higher2 = num4;
  }

  if (num5 > higher1) {
      higher2 = higher1;
      higher1 = num5;
  } else if (num5 > higher2) {
      higher2 = num5;
  }

  printf("Soma dos 2 maiores: %f + %f = %f", higher1, higher2, higher1 + higher2);
}