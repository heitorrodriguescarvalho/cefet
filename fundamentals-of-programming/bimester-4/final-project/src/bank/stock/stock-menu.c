#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "stock-menu.h"
#include "stock-db.h"
#include "../bank-account/bank-account-db.h"
#include "../order/order-db.h"
#include "../../auth/auth.h"
#include "../../account/account.h"
#include "../../menu/menu.h"
#include "../../utils/utils.h"
#include "../../graph/graph.h"

void Stocks_pagination()
{
  int i, input, pages, current_page = 0, initial_index, last_stock_index;

  last_stock_index = Count_stocks();

  pages = ceil(last_stock_index / 8.0);

  while (1)
  {
    system("clear");

    printf("Ações (%d/%d): \n\n", current_page + 1, pages);

    initial_index = current_page * 8;

    for (i = initial_index; i < initial_index + 8; i++)
    {
      if (i >= last_stock_index)
        break;

      printf(" %d. %s\n", i - initial_index + 2, Get_stock_by_index(i).symbol);
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
        Select_stock_options(Get_stock_by_index(input + initial_index - 2).symbol);
      else
        Message("Entrada inválida...");
      break;
    }
  }
}

void Select_stock_options(char stock_symbol[])
{
  int i, input;
  Stock stock;
  Graph graph;

  while (1)
  {
    system("clear");

    stock = Update_stock_price(stock_symbol);

    strcpy(graph.title, stock.symbol);

    for (i = 0; i < 30; i++)
      graph.values[i] = stock.price_history[i + stock.last_price_index - 30];

    Print_graph(graph, "R$", "Cada linha representa uma passagem de tempo de 10 segundos.");

    printf("1. Comprar\n2. Vender\n3. Ver posição\n4. Voltar\n\nEscolha uma opção: ");
    scanf("%d", &input);

    switch (input)
    {
    case 1:
      Buy_stock_options(stock.symbol);
      break;
    case 2:
      Sell_stock_options(stock.symbol);
      break;
    case 3:
      Check_position(stock.symbol);
      break;
    case 4:
      return;
      break;
    default:
      Message("Entrada inválida...");
      break;
    }
  }
}

void Buy_stock_options(char stock_symbol[])
{
  int input;
  Stock stock;

  while (1)
  {
    stock = Update_stock_price(stock_symbol);

    system("clear");
    printf("Comprando %s (R$%.2f)\n\n", stock.symbol, stock.price_history[stock.last_price_index]);

    printf("Tipo de ordem:\n\n1. Mercado\n2. Limitada\n3. Voltar\n\nEscolha uma opção: ");
    scanf("%d", &input);

    switch (input)
    {
    case 1:
      Buy_stock_at_market_price_options(stock_symbol);
      return;
      break;
    case 2:
      Buy_stock_at_limit_price_options(stock_symbol);
      break;
    case 3:
      return;
      break;
    default:
      Message("Entrada inválida...");
      break;
    }
  }
}

void Buy_stock_at_market_price_options(char stock_symbol[])
{
  int quantity, input;
  Account *account = Get_current_account();
  Bank_account *bank_account = &account->bank_account;
  Stock stock;

  while (1)
  {
    stock = Update_stock_price(stock_symbol);

    system("clear");

    printf("Comprando %s (R$%.2f)\n\nÚltima atualização de preço: %s\n", stock.symbol, stock.price_history[stock.last_price_index], ctime(&stock.last_update_at));

    printf("Digite a quantidade: ");
    scanf("%d", &quantity);

    stock = Update_stock_price(stock_symbol);

    if (quantity <= 0)
    {
      input = Try_again("Quantidade inválida...");

      if (!input)
        return;
    }
    else if (bank_account->balance < stock.price_history[stock.last_price_index] * quantity)
    {
      input = Try_again("Saldo Insuficiente...");

      if (!input)
        return;
    }
    else
    {
      stock = Update_stock_price(stock_symbol);

      input = Confirm("Confirma a compra de %d %s por R$%.2f?", quantity, stock.symbol, stock.price_history[stock.last_price_index] * quantity);

      if (!input)
        return;

      Create_buy_order(stock.symbol, quantity, 0);
      return;
    }
  }
}

void Buy_stock_at_limit_price_options(char stock_symbol[])
{
  int quantity, input;
  double limit_price;
  Bank_account *bank_account = Get_current_bank_account();
  Stock stock;

  while (1)
  {
    stock = Update_stock_price(stock_symbol);

    system("clear");

    printf("Comprando %s (R$%.2f)\n\nÚltima atualização de preço: %s\n", stock.symbol, stock.price_history[stock.last_price_index], ctime(&stock.last_update_at));

    printf("Digite a quantidade: ");
    scanf("%d", &quantity);

    if (quantity <= 0)
    {
      input = Try_again("Quantidade inválida...");

      if (!input)
        return;
    }
    else
    {
      stock = Update_stock_price(stock_symbol);

      system("clear");

      printf("Comprando %s (R$%.2f)\n\nÚltima atualização de preço: %s\n", stock.symbol, stock.price_history[stock.last_price_index], ctime(&stock.last_update_at));

      printf("Digite o preço limite: R$");
      scanf("%lf", &limit_price);

      if (limit_price <= 0)
      {
        input = Try_again("Preço limite inválido...");

        if (!input)
          return;
      }
      else if (bank_account->balance < limit_price * quantity)
      {
        input = Try_again("Saldo Insuficiente...");

        if (!input)
          return;
      }
      else
      {
        stock = Update_stock_price(stock_symbol);

        input = Confirm("Confirma a ordem de compra de %d %s por R$%.2f?", quantity, stock.symbol, limit_price * quantity);

        if (!input)
          return;

        Create_buy_order(stock.symbol, quantity, limit_price);
        return;
      }
    }
  }
}

void Sell_stock_options(char stock_symbol[])
{
  int input;
  Stock stock;

  while (1)
  {
    stock = Update_stock_price(stock_symbol);

    system("clear");
    printf("Vendendo %s (R$%.2f)\n\n", stock.symbol, stock.price_history[stock.last_price_index]);

    printf("Tipo de ordem:\n\n1. Mercado\n2. Limitada\n3. Voltar\n\nEscolha uma opção: ");
    scanf("%d", &input);

    switch (input)
    {
    case 1:
      Sell_stock_at_market_price_options(stock_symbol);
      return;
      break;
    case 2:
      Sell_stock_at_limit_price_options(stock_symbol);
      break;
    case 3:
      return;
      break;
    default:
      Message("Entrada inválida...");
      break;
    }
  }
}

void Sell_stock_at_market_price_options(char stock_symbol[])
{
  int quantity, input;
  Stock stock;

  while (1)
  {
    stock = Update_stock_price(stock_symbol);

    system("clear");

    printf("Vendendo %s (R$%.2f)\n\nÚltima atualização de preço: %s\n", stock.symbol, stock.price_history[stock.last_price_index], ctime(&stock.last_update_at));

    printf("Digite a quantidade: ");
    scanf("%d", &quantity);

    if (quantity <= 0)
    {
      input = Try_again("Quantidade inválida...");

      if (!input)
        return;
    }
    else if (quantity > Get_account_stock_by_symbol(stock.symbol)->quantity)
    {
      input = Try_again("Quantidade maior do que a em custódia...");

      if (!input)
        return;
    }
    else
    {
      stock = Update_stock_price(stock_symbol);

      input = Confirm("Confirma a ordem de venda de %d %s por R$%.2f?", quantity, stock.symbol, stock.price_history[stock.last_price_index] * quantity);

      if (!input)
        return;

      Create_sell_order(stock.symbol, quantity, 0);
      return;
    }
  }
}

void Sell_stock_at_limit_price_options(char stock_symbol[])
{
  int quantity, input;
  double limit_price;
  Stock stock;

  while (1)
  {
    stock = Update_stock_price(stock_symbol);

    system("clear");

    printf("Vendendo %s (R$%.2f)\n\nÚltima atualização de preço: %s\n", stock.symbol, stock.price_history[stock.last_price_index], ctime(&stock.last_update_at));

    printf("Digite a quantidade: ");
    scanf("%d", &quantity);

    if (quantity <= 0)
    {
      input = Try_again("Quantidade inválida...");

      if (!input)
        return;
    }
    else if (quantity > Get_account_stock_by_symbol(stock.symbol)->quantity)
    {
      input = Try_again("Quantidade maior do que a em custódia...");

      if (!input)
        return;
    }
    else
    {
      stock = Update_stock_price(stock_symbol);

      system("clear");

      printf("Vendendo %s (R$%.2f)\n\nÚltima atualização de preço: %s\n", stock.symbol, stock.price_history[stock.last_price_index], ctime(&stock.last_update_at));

      printf("Digite o preço limite: R$");
      scanf("%lf", &limit_price);

      if (limit_price <= 0)
      {
        input = Try_again("Preço limite inválido...");

        if (!input)
          return;
      }
      else
      {
        stock = Update_stock_price(stock_symbol);

        input = Confirm("Confirma a ordem de venda de %d %s por R$%.2f?", quantity, stock.symbol, limit_price * quantity);

        if (!input)
          return;

        Create_sell_order(stock.symbol, quantity, limit_price);
        return;
      }
    }
  }
}

void Check_position(char stock_symbol[])
{
  Stock *stock = Get_account_stock_by_symbol(stock_symbol);

  system("clear");

  printf("Posição de %s\n\nQuantidade: %d\nPreço médio: R$%.2f\n\n", stock->symbol, stock->quantity, stock->average_price);

  Await_enter();
}

void Stock_positions_pagination()
{
  int i, input, pages, current_page = 0, initial_index, last_stock_index;
  Stock stock;

  last_stock_index = Count_current_user_owned_stocks();

  pages = ceil(last_stock_index / 8.0);

  if (pages == 0)
    pages = 1;

  while (1)
  {
    system("clear");

    Check_open_orders();

    printf("Ações (%d/%d):\n\n  |  Ação  | Quantidade | Preço médio\n", current_page + 1, pages);
    printf("--|--------|------------|------------\n");
    initial_index = current_page * 8;

    for (i = initial_index; i < initial_index + 8; i++)
    {
      stock = Get_current_user_stock_by_index(i);

      if (i > last_stock_index)
        break;

      printf("%d | %6s | %10d | R$%6.2f\n", i - initial_index + 2, stock.symbol, stock.quantity, stock.average_price);
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
        Select_stock_options(Get_current_user_stock_by_index(initial_index + input - 2).symbol);
      else
        Message("Entrada inválida...");
      break;
    }
  }
}