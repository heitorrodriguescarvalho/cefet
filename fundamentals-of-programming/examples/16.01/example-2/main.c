#include <stdio.h>
#include <stdlib.h>
#include "user.h"

int main()
{
  User user;

  Get_user(&user);
  Print_user(user);

  return 0;
}