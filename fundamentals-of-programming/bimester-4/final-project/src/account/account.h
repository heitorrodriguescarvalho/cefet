#ifndef ACCOUNT_H
#define ACCOUNT_H
#include "../bank/bank-account/bank-account-db.h"

typedef struct
{
  char name[100];
  char id[30];
  char password[80];
  Bank_account bank_account;
} Account;

Account *Get_account_by_id(char[]);
Account *Create_account(char[], char[], char[]);

Account *Get_account_with_user_prompt(char[]);
int Validate_password_with_user_prompt(Account *account);

#endif