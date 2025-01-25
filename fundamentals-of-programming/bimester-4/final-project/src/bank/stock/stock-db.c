#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include "stock-db.h"
#include "../../auth/auth.h"
#include "../order/order-db.h"
#include "../bond/bond-db.h"

#define STOCKS_NUM 50

// Database
Stock stocks[STOCKS_NUM], current_user_owned_stocks[STOCKS_NUM];
int last_stock_index = 0, last_current_user_owned_stock_index = -1, last_order_count = 0;

// Database functions
Stock *Create_stock(char symbol[], double initial_price)
{
  Stock stock;

  strcpy(stock.symbol, symbol);
  stock.price_history[0] = initial_price;
  stock.last_price_index = 0;
  stock.average_price = 0;
  stock.last_update_at = time(NULL);

  stocks[last_stock_index] = stock;

  last_stock_index++;

  return &stocks[last_stock_index - 1];
}

int Count_stocks()
{
  return last_stock_index;
}

Stock Get_stock_by_symbol(char stock_symbol[])
{
  int i;

  for (i = 0; i < last_stock_index; i++)
  {
    if (strcmp(stocks[i].symbol, stock_symbol) == 0)
      return stocks[i];
  }
}

Stock Get_stock_by_index(int index)
{
  return stocks[index];
}

Stock Get_current_user_stock_by_index(int index)
{
  Update_current_user_owned_stocks();

  return current_user_owned_stocks[index];
}

int Count_current_user_owned_stocks()
{
  Update_current_user_owned_stocks();

  return last_current_user_owned_stock_index;
}

void Update_current_user_owned_stocks()
{
  int i, current_orders_count = Count_orders();
  Bank_account *bank_account = Get_current_bank_account();

  if (current_orders_count == last_order_count)
    return;

  last_order_count = current_orders_count;

  last_current_user_owned_stock_index = -1;

  for (i = 0; i < last_stock_index; i++)
    if (bank_account->stocks[i].quantity > 0)
    {
      last_current_user_owned_stock_index++;
      current_user_owned_stocks[last_current_user_owned_stock_index] = bank_account->stocks[i];
    }
}

int Buy_stock_at_market_price(char account_id[], char stock_symbol[], int quantity)
{
  Bank_account *bank_account = &Get_account_by_id(account_id)->bank_account;
  Stock stock, *account_stock;

  stock = Get_stock_by_symbol(stock_symbol);

  double total_price = stock.price_history[stock.last_price_index] * quantity;

  account_stock = Get_account_stock_by_symbol(stock.symbol);

  if (bank_account->balance < total_price)
    return 3;

  bank_account->balance -= total_price;

  account_stock->average_price = (account_stock->average_price * account_stock->quantity + total_price) / (quantity + account_stock->quantity);
  account_stock->quantity += quantity;

  return 1;
}

int Sell_stock_at_market_price(char account_id[], char stock_symbol[], int quantity)
{
  Bank_account *bank_account = &Get_account_by_id(account_id)->bank_account;
  Stock stock, *account_stock;

  stock = Get_stock_by_symbol(stock_symbol);

  double total_price = stock.price_history[stock.last_price_index] * quantity;

  account_stock = Get_account_stock_by_symbol(stock.symbol);

  if (account_stock->quantity < quantity)
    return 3;

  bank_account->balance += total_price;

  account_stock->quantity -= quantity;

  return 1;
}

// Stocks logic
void Initialize_stocks()
{
  int i;
  double initial_price;
  char stock_symbols[STOCKS_NUM][7] = {
      "PETR3", "PETR4", "VALE3", "ITUB4", "BBDC3",
      "BBDC4", "ABEV3", "WEGE3", "GGBR3", "CMIG4",
      "ITSA4", "LREN3", "EGIE3", "SUZB3", "EMBR3",
      "CSNA3", "BBAS3", "KROT3", "JBSS3", "RAIL3",
      "QUAL3", "MGLU3", "VVAR3", "CVCB3", "BTOW3",
      "TIMS3", "SBSP3", "RENT3", "PSSA3", "HYPE3",
      "BRFS3", "GOAU3", "RUMO3", "B3SA3", "UGPA3",
      "TIMP3", "ENGI11", "TRPL4", "POSI3", "GOLL4",
      "BRKM5", "LAME4", "CIEB3", "PCAR3", "ARZZ3",
      "CIEL3", "RADL3", "SLED3", "IRBR3", "MLAS3"};

  for (i = 0; i < 50; i++)
  {
    initial_price = ((rand() + 10) % 20000) / 100.0;
    Create_stock(stock_symbols[i], initial_price);
  }
}

void Generate_new_stock_price(char stock_symbol[])
{
  double price_difference = ((rand() % 41) * 0.01) - 0.2;
  Stock *stock = Get_db_stock_by_symbol(stock_symbol);

  if (stock->price_history[stock->last_price_index] + price_difference < 0)
    price_difference *= -1;

  stock->price_history[stock->last_price_index + 1] = stock->price_history[stock->last_price_index] + price_difference;

  stock->last_price_index++;

  Check_open_orders();
}

Stock Update_stock_price(char stock_symbol[])
{
  time_t now;
  int num_updates, i;
  Stock *stock = Get_db_stock_by_symbol(stock_symbol);

  Update_bonds();

  Check_open_orders();

  time(&now);

  if (stock->last_price_index == 0)
    for (i = 0; i < 30; i++)
      Generate_new_stock_price(stock_symbol);

  num_updates = (int)floor(difftime(now, stock->last_update_at) / 10);

  for (i = 0; i < num_updates; i++)
    Generate_new_stock_price(stock_symbol);

  stock->last_update_at = now;

  return Get_stock_by_symbol(stock_symbol);
}

// Helpers
Stock *Get_db_stock_by_symbol(char stock_symbol[])
{
  int i;

  for (i = 0; i < last_stock_index; i++)
  {
    if (strcmp(stocks[i].symbol, stock_symbol) == 0)
      return &stocks[i];
  }

  return NULL;
}

Stock *Get_account_stock_by_symbol(char stock_symbol[])
{
  int i;
  Bank_account *bank_account = Get_current_bank_account();

  for (i = 0; i < 50; i++)
    if (strcmp(bank_account->stocks[i].symbol, stock_symbol) == 0)
      return &bank_account->stocks[i];

  return NULL;
}