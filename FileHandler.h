// FileHandler.h
#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include "Account.h"

void writeAccountToFile(const Account& account);
void readAccountFromFile(int accountNumber, Account& account);
void modifyAccountInFile(const Account& account);
void deleteAccountFromFile(int accountNumber);
void displayAllAccounts();

#endif // FILEHANDLER_H