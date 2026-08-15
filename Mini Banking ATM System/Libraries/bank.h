#ifndef BANK_H
#define BANK_H
#include "../Libraries/STD_TYPES.h"
typedef enum {
    SAVINGS,
    CURRENT
} AccountType ;

typedef struct {
    u8 accountNumber[12];
    u8 name[40];
    u8 pin[5];
    AccountType type;
    f32  balance;
    u32 depositCount;
    u32 withdrawalCount;
} Account ; 


Account *login(Account *list[], u32 count);

void showBalance(const Account *account);

void deposit(Account *account);

void withdraw(Account *account);

void showSummary(const Account *account);

#endif