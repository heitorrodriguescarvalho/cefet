#include <stdio.h>
#include <stdlib.h>

int ChooseOption(int value)
{
  int option;

  printf("Opções de Pagamento:\n");
  printf("\t(1) A vista: 10%% de desconto:\n");
  printf("\t(2) Parcelado 2x: preço de etiqueta\n");

  if (value > 100)
    printf("\t(3) Parcelado 3x a 10x: 3%% de juros mensais\n\n");

  printf("Digite sua opção: ");
  scanf("%d", &option);

  if (option < 1 || (value > 100 && option > 3) || (value <= 100 && option > 2))
  {
    printf("Opção Inválida\n\n");
    return ChooseOption(value);
  }

  return option;
}

float FirstOption(float value)
{
  return value * 0.9;
}

float SecondOption(float value)
{
  return value / 2;
}

float ThirtyOption(float value, int divided)
{
  return value * (0.03 * divided + 1) / divided;
}

main()
{
  float value, montlyValue;
  int divided;

  printf("Digite o valor gasto: R$");
  scanf("%f", &value);

  int option = ChooseOption(value);

  switch (option)
  {
  case 1:
    montlyValue = FirstOption(value);
    divided = 1;
    break;

  case 2:
    montlyValue = SecondOption(value);
    divided = 2;
    break;

  case 3:
    do
    {
      printf("Número de parcelas (3 a 10): ");
      scanf("%d", &divided);

      if (divided < 3 || divided > 10)
        printf("Número de parcelas inválido!\n");
    } while (divided < 3 || divided > 10);

    montlyValue = ThirtyOption(value, divided);
  }

  printf("Total a pagar: %d parcela(s) de R$%.2f", divided, montlyValue);
}