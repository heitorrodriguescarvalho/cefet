#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "auth/auth.h"
#include "bank/stock/stock-db.h"
#include "bank/bond/bond-db.h"

int main()
{
  srand(time(NULL));

  Initialize_stocks();

  Initialize_bonds();

  Select_auth_option();

  return 0;
}