#include <stdio.h>

#include "../Libraries/ATM.h"
#include "../Libraries/bank.h"
#include "../Libraries/STD_TYPES.h"

#define ACC_COUNT 6 
u32 main(){


    Account accounts[ACC_COUNT] = {
        {"1001", "Moaaz Hesham", "1234", SAVINGS, 5000.0f, 0, 0}, 
        {"1002", "Youssef Mohamed",  "5678", CURRENT, 3500.0f, 0, 0}, 
        {"1003", "Abdelrahman Adel",  "4321", SAVINGS, 7200.0f, 0, 0},
        {"1004", "Abdelrahman Mourad",  "5712", SAVINGS, 9300.0f, 0, 0},
        {"1005", "Mohamed Abdelrahman",  "9017", CURRENT, 4600.0f, 0, 0},
        {"1006", "Fatma Eslam",  "2026", CURRENT, 7600.0f, 0, 0}
    };
    
    Account *accountsPointers[ACC_COUNT];
    for (u32 i = 0 ; i < ACC_COUNT ; i++){
        accountsPointers[i] = &accounts[i] ; 
    }

    Account *currentAccount;
    
    while(1){

    printf("========================================\n");
    printf("        MINI BANKING & ATM SYSTEM       \n");
    printf("========================================\n");

    int attempts = 0 ; 
    currentAccount = NULL ; 

    while (attempts < 3 )
    {


    currentAccount = login(accountsPointers,ACC_COUNT);

    if (currentAccount != NULL){
        printf("Login succesful! \n");
        printf("Welcome, %s\n",currentAccount->name);

        atmMenu(currentAccount);
    }
    else{
        attempts++;
        printf("Login failed! \n");
        printf("Attempts remaining: %d\n", 3 - attempts);
    }

    }

    if (attempts == 3 && currentAccount == NULL){
        printf("\nAccess denied. Maximum login attempts reached.\n");
        break;
    }
 }

}