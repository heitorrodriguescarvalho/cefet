#ifndef BOND_DB_H
#include <time.h>
#define BOND_DB_H

typedef struct
{
  char name[26];
  char rate_label[26];
  double investment_value;
  double annual_interest_rate;
  int total_months_to_expire;
  int months_expired;
  time_t last_update_at;
} Bond;

Bond *Create_bond(char[], char[], double);
Bond Get_bond_by_index(int);
Bond Get_bond_by_name(char[]);
int Count_bonds();
void Buy_bond(char[], double, float);
void Update_bonds();
void Initialize_bonds();

#endif