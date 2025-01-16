typedef struct
{
  int id;
  char name[50];
  double balance;
} BankAccount;

void Init(BankAccount *, int, char[], double);
void Deposit(BankAccount *, double);
void Withdraw(BankAccount *, double);
void Print(BankAccount);
