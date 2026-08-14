#include <stdio.h>
#include <string.h>
#include "../Libraries/bank.h"
#include "../Libraries/STD_TYPES.h"

Account *login(Account *list[], u32 count){
    u8 accountNumber[12];
    u8 pin[5];

    printf("Enter account number: ");
    scanf("%11s", accountNumber);

    printf("Enter PIN: ");
    scanf("%4s", pin);

    for(u32 i=0 ; i < count; i++){
        if(strcmp(accountNumber,list[i]->accountNumber) == 0
         && strcmp(pin,list[i]->pin) == 0){
            return list[i] ; 
         }
    }
    return NULL ; 
}

void showBalance(const Account *account){
    printf("Costumer: %s \n",account->name);
    printf("Balance: %.2f \n",account->balance);
}

void deposit(Account *account){

    f32 amount ; 
    printf("Enter amount to deposit: ");
    scanf("%f",&amount);

    if (amount>0){
        account->balance += amount ; 
        account->depositCount++;

        printf("Deposit succesful!\n");
        printf("New Balance: %.2f\n",account->balance);
    }
    else{  printf("Invalid amount!\n");}
}

void withdraw(Account *account){
    f32 amount;

    printf("Enter amount to withdraw: ");
    scanf("%f",&amount);

    if (amount > 0 && amount <= account->balance){
        account->balance-=amount ;
        account->withdrawalCount++;

        printf("Withdrawal succesful!\n");
        printf("New Balance: %.2f\n",account->balance);
    }
    else{
        printf("Invalid amount or insufficient balance!\n");
    }
}
void showSummary(const Account *account){
    printf("\n------ Session Summary -----\n");
    printf("Customer: %s\n",account->name);
    printf("Balance: %.2f\n",account->balance);
    printf("Deposits: %u\n",account->depositCount);
    printf("Withdrawals: %u\n",account->withdrawalCount);
}


