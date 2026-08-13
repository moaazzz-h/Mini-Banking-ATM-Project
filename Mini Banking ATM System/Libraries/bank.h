#ifndef BANK_H
#define BANK_H

typedef enum {
    SAVINGS,
    CURRENT
} AccountType ;

typedef struct {
    char accountNumber[12];
    char name[40];
    char pin[5];
    AccountType type;
    float balance;
    int depositCount;
    int withdrawalCount;
} Account ; 


Account *login(Account *list[], int count);

void showBalance(const Account *account);

void deposit(Account *account);

void withdraw(Account *account);

void showSummary(const Account *account);

#endif