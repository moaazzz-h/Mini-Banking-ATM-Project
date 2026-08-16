#include <stdio.h>

#include "../Libraries/File_Handler.h"
#include "../Libraries/bank.h"
#include "../Libraries/Standard_Types.h"



u32 saveAccounts(Account accounts[], u32 count)
{
    FILE *file;

    file = fopen(ACCOUNTS_FILE, "w");

    if (file == NULL) {
        printf("[Error] Could not open accounts file!\n");
        return 0;
    }

    for (u32 i = 0; i < count; i++) {

        fprintf(file, "%s|%s|%s|%d|%.2f|%u|%u\n",
                accounts[i].accountNumber,
                accounts[i].name,
                accounts[i].pin,
                accounts[i].type,
                accounts[i].balance,
                accounts[i].depositCount,
                accounts[i].withdrawalCount);
    }

    fclose(file);

    return 1;
}


u32 loadAccounts(Account accounts[], u32 count)
{
    FILE *file;
    u32 type;

    file = fopen(ACCOUNTS_FILE, "r");

    if (file == NULL) {
        return 0;
    }

    for (u32 i = 0; i < count; i++) {

        if (fscanf(file, " %11[^|]|%39[^|]|%4[^|]|%d|%f|%u|%u",
                   accounts[i].accountNumber,
                   accounts[i].name,
                   accounts[i].pin,
                   &type,
                   &accounts[i].balance,
                   &accounts[i].depositCount,
                   &accounts[i].withdrawalCount) != 7) {

            fclose(file);
            return 0;
        }

        accounts[i].type = (AccountType)type;
    }

    fclose(file);

    return 1;
}
