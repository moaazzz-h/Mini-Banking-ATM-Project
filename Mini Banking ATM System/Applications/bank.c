#include <stdio.h>
#include <string.h>
#include "../Libraries/bank.h"

Account *login(Account *list[], int count){
    char accountNumber[12];
    char pin[5];

    printf("Enter account number: ");
    scanf("%11s", accountNumber);

    printf("Enter PIN: ");
    scanf("%4s", pin);

    for(int i=0 ; i < count; i++){
        if(strcmp(accountNumber,list[i]->accountNumber) == 0
         && strcmp(pin,list[i]->pin) == 0){
            return list[i] ; 
         }
    }
    return NULL ; 
}