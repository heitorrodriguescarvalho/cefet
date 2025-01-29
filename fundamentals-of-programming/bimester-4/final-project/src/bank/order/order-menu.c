#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "order-menu.h"
#include "order-db.h"
#include "../../menu/menu.h"
#include "../../utils/utils.h"

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

    printf("Ordens (%d/%d):\n\n  | Código |  Ação  |  Status   |  Tipo   |  Preço   | Quantidade\n", current_page + 1, pages);
    printf("--|--------|--------|-----------|---------|----------|-----------\n");
    initial_index = current_page * 8;

    for (i = initial_index; i < initial_index + 8; i++)
    {
      order = Get_order_by_index(i);

      if (i > last_order_index)
        break;

      printf("%d | %6s | ", i - initial_index + 2, order.stock_symbol);

      if (order.type == 0)
        printf("Compra | ");
      else
        printf("Venda  | ");

      switch (order.status)
      {
      case 0:
        printf("Aberta    | ");
        break;
      case 1:
        printf("Executada | ");
        break;
      case 2:
        printf("Cancelada | ");
        break;
      case 3:
        printf("Falhou    | ");
        break;
      }

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
      if (input >= 2 && input <= i - initial_index + 1)
        Select_order_options(initial_index + input - 2);
      else
        Message("Entrada inválida...");
      break;
    }
  }
}

void Select_order_options(int index)
{
  int input;
  Order order = Get_order_by_index(index);

  while (1)
  {
    system("clear");

    printf("Ordem de %s\n\n", order.stock_symbol);

    printf("Tipo de ordem: ");
    if (order.type == 0)
      printf("Compra\n");
    else
      printf("Venda\n");

    printf("Quantidade: %d\n", order.quantity);

    printf("Preço limite: ");
    if (order.limit_price == 0)
      printf("Mercado\n");
    else
      printf("R$%.2f\n", order.limit_price);

    printf("Status: ");

    switch (order.status)
    {
    case 0:
      printf("Aberta\n\n");
      break;
    case 1:
      printf("Executada\n\n");
      break;
    case 2:
      printf("Cancelada\n\n");
      break;
    case 3:
      printf("Falhou\n\n");
      break;
    }

    if (order.status != 0)
    {
      Await_enter();
      return;
    }

    printf("1. Cancelar ordem\n2. Voltar\n\nEscolha uma opção: ");
    scanf("%d", &input);

    switch (input)
    {
    case 1:
      if (Get_order_by_index(index).status == 0)
        Cancel_order(index);

      return;
      break;
    case 2:
      return;
      break;
    default:
      Message("Entrada inválida...");
      break;
    }
  }
}