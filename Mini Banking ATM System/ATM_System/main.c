#include <stdio.h>

#include "../Libraries/ATM.h"
#include "../Libraries/bank.h"
#include "../Libraries/Standard_Types.h"
#include "../Libraries/File_Handler.h"

int main()
{
    Account accounts[ACCOUNT_COUNT] = {
        {"1001", "Sara Ahmed", "1234", SAVINGS, 5000.0f, 0, 0},
        {"1002", "Omar Ali", "5678", CURRENT, 3500.0f, 0, 0},
        {"1003", "Mona Adel", "4321", SAVINGS, 7200.0f, 0, 0}
    };

    if (!loadAccounts(accounts, ACCOUNT_COUNT)) {
        saveAccounts(accounts, ACCOUNT_COUNT);
    }

    Account *accountPointers[ACCOUNT_COUNT];

    for (u32 i = 0; i < ACCOUNT_COUNT; i++) {
        accountPointers[i] = &accounts[i];
    }

    while (1) {

        Account *acc = login(accountPointers, ACCOUNT_COUNT);

        if (acc != NULL) {

            atmMenu(acc);

            saveAccounts(accounts, ACCOUNT_COUNT);

        }
        else {

            printf("\n[System Locked] Access Denied. Exiting program...\n");
            break;
        }
    }

    return 0;
}
