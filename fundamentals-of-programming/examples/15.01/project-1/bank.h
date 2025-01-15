typedef struct
{
  int id;
  double balance;
} BankAccount;

void Init(BankAccount *, int, double);
void Deposit(BankAccount *, double);
void Withdraw(BankAccount *, double);
void Print(BankAccount);
