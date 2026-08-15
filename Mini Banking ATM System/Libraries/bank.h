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


#endif
