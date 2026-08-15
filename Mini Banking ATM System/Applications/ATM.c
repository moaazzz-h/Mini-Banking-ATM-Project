#include <stdio.h>
#include "../Libraries/ATM.h"
#include "../Libraries/STD_TYPES.h"

void atmMenu(Account *account){
    u32 choice ;
    void (*operation)(Account *);

    while(1){
        printf("\n----- ATM MENU -----\n");
        printf("1. Check balance\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Session Summary\n");
        printf("5. Logout\n");

        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
            showBalance(account);
            break;
        case 2:
            operation = deposit;
            operation(account);
            break;
        case 3:
            operation = withdraw;
            operation(account);
            break;
        case 4:
            showSummary(account);
            break;
        case 5:
            return;
        
        default:
            printf("Invalid Choice!\n");
            break;
        }


    }
}