#ifndef FILE_HANDLER_H
#define FILE_HANDLER_H

#include "bank.h"
#include "Standard_Types.h"

#define ACCOUNTS_FILE "accounts.txt"

u32 loadAccounts(Account accounts[], u32 count);
u32 saveAccounts(Account accounts[], u32 count);

#endif
