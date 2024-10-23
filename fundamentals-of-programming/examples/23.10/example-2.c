#include <stdio.h>
#include <stdlib.h>

void SumAndPrint(float n1, float n2)
{
  printf("Soma entre %.2f e %.2sf: %.2f", n1, n2, n1 + n2);
}

main()
{
  float n1, n2;

  printf("Digite dois núemeros:\n");
  scanf("%f %f", &n1, &n2);

  SumAndPrint(n1, n2);
}