#ifndef ORDER_H
#define ORDER_H

typedef struct
{
  char stock_symbol[6];
  char account_id[30];
  int quantity;
  double limit_price;
  int status; // 0. Open; 1. Closed; 2. Canceled; 3. Failed
  int type;   // 0. Buy; 1. Sell
} Order;

void Create_order(char[], int, double, int);
void Create_buy_order(char[], int, double);
void Create_sell_order(char[], int, double);
int Count_orders();
void Cancel_order(int);
Order Get_order_by_index(int);
void Update_current_account_orders();
void Check_open_orders();

#endif