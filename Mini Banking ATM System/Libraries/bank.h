#ifndef BANK_H
#define BANK_H

#define ACCOUNT_COUNT 3
#define MAX_ATTEMPTS 3
typedef enum {
    SAVINGS,
    CURRENT
} AccountType;

typedef struct {
    char accountNumber[12];
    char name[40];
    char pin[5];
    AccountType type;
    float balance;
    int depositCount;
    int withdrawalCount;
} Account;

typedef enum{
    CHECK_BALANCE =1,
    DEPOSIT,
    WITHDRAW,
    CHANGE_PIN,
    SESSION_SUMMARY,
    LOGOUT
}Menu;

Account *login(Account *list[], int count);
void atmMenu(Account *account);
void showBalance(const Account *account);
void deposit(Account *account);
void withdraw(Account *account);
void showSummary(const Account *account);
int changePin(Account *account);
#endif
