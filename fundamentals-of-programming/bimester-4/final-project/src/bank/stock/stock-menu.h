#ifndef STOCK_H
#include <time.h>
#define STOCK_H

void Stocks_pagination();
void Select_stock_options(char[]);

void Buy_stock_options(char[]);
void Buy_stock_at_market_price_options(char[]);
void Buy_stock_at_limit_price_options(char[]);

void Sell_stock_options(char[]);
void Sell_stock_at_market_price_options(char[]);
void Sell_stock_at_limit_price_options(char[]);

void Check_position(char[]);
void Stock_positions_pagination();

#endif