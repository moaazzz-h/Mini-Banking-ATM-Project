#ifndef BANK_H
#define BANK_H

#define ACCOUNT_COUNT 3
#define MAX_ATTEMPTS 3
#include "Standard_Types.h"

typedef enum {
    SAVINGS,
    CURRENT
} AccountType;

typedef struct {
    u8 accountNumber[12];
    u8 name[40];
    u8 pin[5];
    AccountType type;
    f32 balance;
    u32 depositCount;
    u32 withdrawalCount;
} Account;


#endif
