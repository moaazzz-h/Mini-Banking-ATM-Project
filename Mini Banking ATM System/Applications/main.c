#include <stdio.h>

#include "../Libraries/ATM.h"
#include "../Libraries/bank.h"

#define ACC_COUNT 6 
int main()
{
    Account accounts[ACC_COUNT] = {
        {"1001", "Moaaz Hesham", "1234", SAVINGS, 5000.0f, 0, 0}, 
        {"1002", "Youssef Mohamed",  "5678", CURRENT, 3500.0f, 0, 0}, 
        {"1003", "Abdelrahman Adel",  "4321", SAVINGS, 7200.0f, 0, 0},
        {"1004", "Abdelrahman Mourad",  "5712", SAVINGS, 9300.0f, 0, 0},
        {"1005", "Mohamed Abdelrahman",  "9017", CURRENT, 4600.0f, 0, 0},
        {"1006", "Fatma Eslam",  "2026", CURRENT, 7600.0f, 0, 0}
    };
    Account *accountsPointers[ACC_COUNT];
    for (int i = 0 ; i < ACC_COUNT ; i++){
        accountsPointers[i] = &accounts[i] ; 
    }

    Account *currentAccount;

    currentAccount = login(accountsPointers,ACC_COUNT);

    if (currentAccount != NULL){
        printf("Login succesful! \n");
        printf("Welcome, %s\n",currentAccount->name);
    }
    else{
        printf("Login failed! \n");
    }

}