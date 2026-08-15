#include <stdio.h>
#include "..//Libraries/bank.h"
#include "..//Libraries/ATM.h"
#include "..//Libraries/Standard_Types.h"


void atmMenu(Account *account){
    u32  choose;
    while(1){
    printf("---------------ATM MENU---------------\n");
    printf("\n 1.Check Balance \n 2.Deposit \n 3.Withdraw \n 4.Change PIN \n 5.Session Summary \n 6.Logout \n");
    printf("please choose Number of Operation :");
    if (scanf("%d", &choose) != 1) {
            printf("\n[Error] Invalid input. Please enter a number from 1 to 6.\n");
            while (getchar() != '\n');
            continue;
        }

    switch (choose){
       case CHECK_BALANCE:
         showBalance(account);
         break;
       case DEPOSIT:
         deposit(account);
         break;
       case WITHDRAW:
         withdraw(account);
         break;
       case CHANGE_PIN:
         if (changePin(account) == 1) {
                return;
            }
         break;
       case SESSION_SUMMARY:
         showSummary(account);
         break;
       case LOGOUT:
        printf("\nThank you for using our ATM. Goodbye, %s!\n", account->name);
        return;

       default:
        printf("\n[Error] Invalid option! Please choose between 1 and 6.\n");
         break;


      }
    }

}
