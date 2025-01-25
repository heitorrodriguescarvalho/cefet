#ifndef STOCK_DB_H
#include <time.h>
#define STOCK_DB_H

typedef struct
{
  char symbol[6];
  double price_history[10000];
  double average_price;
  int last_price_index;
  int quantity;
  time_t last_update_at;
} Stock;

Stock *Create_stock(char[], double);
int Count_stocks();
Stock Get_stock_by_index(int);
Stock Get_stock_by_symbol(char[]);

int Buy_stock_at_market_price(char[], char[], int);
int Sell_stock_at_market_price(char[], char[], int);

Stock Get_current_user_stock_by_index(int);
int Count_current_user_owned_stocks();
void Update_current_user_owned_stocks();

void Initialize_stocks();
void Generate_new_stock_price(char[]);
Stock Update_stock_price(char[]);

Stock *Get_db_stock_by_symbol(char[]);
Stock *Get_account_stock_by_symbol(char[]);

#endif