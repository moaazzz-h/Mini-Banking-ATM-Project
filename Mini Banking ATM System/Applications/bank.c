#include <stdio.h>
#include <string.h>
#include <windows.h>
#include "..//Libraries/bank.h"


Account *login(Account *list[], int count){
   static int attempts = 0;
   printf("========================================\t\n");
   printf(" MINI BANKING & ATM SYSTEM\t\n");
   printf("========================================\t\n");
   char accountNumber[12];
   char pin[5];
   printf("Please Enter The AccountNumber :");
   scanf("%s",accountNumber);
   printf("Please Enter The pin :");
   scanf("%s",pin);
   for(int i=0;i<count;i++){
    if(strcmp(accountNumber, list[i]->accountNumber) == 0 &&
            strcmp(pin, list[i]->pin) == 0){
        printf("Welcome %s \n",list[i]->name);
        attempts = 0;

        return list[i];
    }
   }

            attempts++;

    if (attempts < MAX_ATTEMPTS){
       printf("\n[!] Invalid Account Number or PIN.\n");
        printf("Please try again. You have %d attempt(s) left.\n", MAX_ATTEMPTS - attempts);
        printf("Please wait 5 seconds...\n");
        Sleep(5000);
        return login(list, count);
    }
    else {
       printf("\n[X] You have exceeded the maximum number of attempts.\n");
        attempts = 0;
        return NULL;
    }




}


void atmMenu(Account *account){
    int  choose;
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
void showBalance(const Account *account){
    printf("---------------ACCOUNT BALANCE---------------\n");
    printf("Name            : %s \n",account->name);
    printf("Account Number  : %s \n",account->accountNumber);
    printf("Account Type    : %s \n", (account->type == SAVINGS) ? "Savings" : "Current");
    printf("Account Balance : %.2f \n",account->balance);
    printf("========================================\n");
}

void deposit(Account *account){
    printf("---------------DEPOSIT OPERATION---------------\n");
    float Amount;
    printf("please Enter The Deposit Amount :");
    if (scanf("%f", &Amount) != 1) {
        printf("[Error] Invalid input format!\n");
        while (getchar() != '\n');
        return;
    }
    if(Amount > 0){
        account->balance +=Amount;
        account->depositCount++;
       printf("[Success] The amount has been successfully deposited.\n");
        printf("Current balance : %.2f EGP\n", account->balance);


    }
    else
       printf("[Error] The amount must be greater than zero!\n");

}

void withdraw(Account *account){
    printf("---------------withdraw OPERATION---------------\n");
    float Amount;
    printf("please Enter The withdraw Amount :");
    if (scanf("%f", &Amount) != 1) {
        printf("[Error] Invalid input format!\n");
        while (getchar() != '\n');
        return;
    }
    if(Amount > 0 && Amount <= account->balance){
        account->balance -=Amount;
        account->withdrawalCount++;
        printf("The amount has been successfully withdrawn.\n");
        printf("Remaining balance :%.2f \n",account->balance);
    }
    else if(Amount <= 0){
         printf("Error:The amount must be greater than zero !\n");
    }
    else
       printf("[Error] Insufficient Balance! Your current balance is %.2f EGP\n", account->balance);

}
int changePin(Account *account){
        char pin[5];
        char NEW_PIN[5];
        int attempts = 0;
        while (attempts < MAX_ATTEMPTS) {
        printf("---------------CHANGE PIN---------------\n");
        printf("Please Enter The Old PIN (Attempt %d/%d): ", attempts + 1, MAX_ATTEMPTS);
        if (scanf("%4s", pin) != 1) {
        while (getchar() != '\n');
        return 0;
    }
    while (getchar() != '\n');
        if(strcmp(account->pin,pin)==0){
          printf("Please Enter The NEW PIN (max 4 digits): ");
          if (scanf("%4s", NEW_PIN) != 1) {
            while (getchar() != '\n');
            return 0;
        }
        while (getchar() != '\n');
         strcpy(account->pin, NEW_PIN);
         printf("\n[Success] PIN has been changed successfully!\n");
         return 0;
        }
        else{
            attempts++;
            printf("\n[!] Invalid Old PIN.\n");

          }
        }

                printf("\n[Security Alert] Too many incorrect attempts! For your security, you are being logged out.\n");
            return 1;

        }



void showSummary(const Account *account){

    printf("--------------------SESSION SUMMARY--------------------\n");
    printf("Customer           :%s \n",account->name);
    printf("Deposits completed :%d \n",account->depositCount);
    printf("Withdrawals        :%d \n",account->withdrawalCount);
    printf("Final balance      :%.2f \n",account->balance);
    printf("-------------------------------------------------------\n");

}









