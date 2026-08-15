#ifndef ATM_H
#define ATM_H

#include "bank.h"
#include "Standard_Types.h"

typedef enum{
    CHECK_BALANCE =1,
    DEPOSIT,
    WITHDRAW,
    CHANGE_PIN,
    SESSION_SUMMARY,
    LOGOUT
}Menu;

Account *login(Account *list[], u32 count);
void atmMenu(Account *account);
void showBalance(const Account *account);
void deposit(Account *account);
void withdraw(Account *account);
void showSummary(const Account *account);
u32 changePin(Account *account);


#endif
