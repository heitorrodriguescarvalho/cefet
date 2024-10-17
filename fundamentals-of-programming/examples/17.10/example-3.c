#include <stdio.h>
#include <stdlib.h>

float CalcCommission(float sells, float commission)
{
  return sells * (commission / 100) * 0.9;
}

void PrintCommission(float commission)
{
  printf("Comissão após taxas: R$%.2f", commission);
}

main()
{
  float sells, commission;

  printf("Digite o total das vendas: R$");
  scanf("%f", &sells);

  printf("Digite o percentual de comissão: ");
  scanf("%f", &commission);

  PrintCommission(CalcCommission(sells, commission));
}