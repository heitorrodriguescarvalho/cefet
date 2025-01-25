#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "order-db.h"
#include "../stock/stock-db.h"
#include "../../auth/auth.h"
#include "../../account/account.h"

// Database
Order orders[10000], current_account_orders[1000];
int last_order_index = -1, last_account_order_index = -1, last_update_orders_count = -1;
char current_account_orders_id[30];

// Database functions
void Create_order(char stock_symbol[], int quantity, double limit_price, int type)
{
  Account *account = Get_current_account();

  last_order_index++;

  strcpy(orders[last_order_index].account_id, account->id);
  strcpy(orders[last_order_index].stock_symbol, stock_symbol);
  orders[last_order_index].quantity = quantity;
  orders[last_order_index].limit_price = limit_price;
  orders[last_order_index].status = 0;
  orders[last_order_index].type = type;

  Update_stock_price(stock_symbol);
}

void Create_buy_order(char stock_symbol[], int quantity, double limit_price)
{
  Create_order(stock_symbol, quantity, limit_price, 0);
}

void Create_sell_order(char stock_symbol[], int quantity, double limit_price)
{
  Create_order(stock_symbol, quantity, limit_price, 1);
}

int Count_orders()
{
  Update_current_account_orders();

  return last_account_order_index;
}

Order Get_order_by_index(int index)
{
  Update_current_account_orders();

  return current_account_orders[index];
}

void Update_current_account_orders()
{
  int i;
  Account *account = Get_current_account();

  if (last_update_orders_count == last_order_index && strcmp(current_account_orders_id, account->id) == 0)
    return;

  last_account_order_index = -1;

  for (i = 0; i <= last_order_index; i++)
    if (strcmp(orders[i].account_id, account->id) == 0)
    {
      last_account_order_index++;

      current_account_orders[last_account_order_index] = orders[i];
    }

  last_update_orders_count = last_order_index;

  strcpy(current_account_orders_id, account->id);
}

void Check_open_orders()
{
  int i;
  Stock stock;

  for (i = 0; i <= last_order_index; i++)
  {
    if (orders[i].status != 0)
      continue;

    stock = Get_stock_by_symbol(orders[i].stock_symbol);

    if (orders[i].type == 1)
    {
      if (stock.price_history[stock.last_price_index] >= orders[i].limit_price || orders[i].limit_price == 0)
        orders[i].status = Sell_stock_at_market_price(orders[i].account_id, orders[i].stock_symbol, orders[i].quantity);
    }
    else if (orders[i].type == 0)
    {
      if (stock.price_history[stock.last_price_index] <= orders[i].limit_price || orders[i].limit_price == 0)
        orders[i].status = Buy_stock_at_market_price(orders[i].account_id, orders[i].stock_symbol, orders[i].quantity);
    }
  }
}