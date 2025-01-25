#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "order-menu.h"
#include "order-db.h"
#include "../../menu/menu.h"

void Orders_pagination()
{
  int i, input, pages, current_page = 0, initial_index, last_order_index;
  Order order;

  last_order_index = Count_orders();

  pages = ceil(last_order_index / 8.0);

  if (pages == 0)
    pages = 1;

  while (1)
  {
    system("clear");

    printf("Ordens (%d/%d):\n\nCódigo |  Ação  | Status  |  Tipo   |  Preço   | Quantidade\n", current_page + 1, pages);
    printf("-------|--------|---------|---------|----------|-----------\n");
    initial_index = current_page * 8;

    for (i = initial_index; i < initial_index + 8; i++)
    {
      order = Get_order_by_index(i);

      if (i > last_order_index)
        break;

      printf("%6s | ", order.stock_symbol);

      if (order.type == 0)
        printf("Compra | ");
      else
        printf("Venda  | ");

      if (order.status == 0)
        printf("Aberta  | ");
      else
        printf("Fechada | ");

      if (order.limit_price == 0)
        printf("Mercado | ");
      else
        printf("Limite  | ");

      if (order.limit_price == 0)
      {
        printf("    -    | ");
      }
      else
      {
        printf("R$%6.2f | ", order.limit_price);
      }

      printf("%d\n", order.quantity);
    }

    printf("\n");

    if (current_page + 1 < pages)
      printf(" 1. Próxima página\n");

    if (current_page - 1 >= 0)
      printf(" 0. Página anterior\n");

    printf("-1. Voltar\n\nEscolha uma opção: ");
    scanf("%d", &input);

    switch (input)
    {
    case 1:
      if (current_page + 1 < pages)
        current_page++;
      else
        Message("Entrada inválida...");
      break;
    case 0:
      if (current_page - 1 >= 0)
        current_page--;
      else
        Message("Entrada inválida...");
      break;
    case -1:
      return;
      break;
    default:
      Message("Entrada inválida...");
      break;
    }
  }
}