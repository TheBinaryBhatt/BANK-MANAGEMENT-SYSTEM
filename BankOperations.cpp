#include "BankOperations.h"
#include "Account.h"
#include "FileHandler.h"
#include <iostream>
using namespace std;

void createAccount() {
    Account account;
    account.createAccount();
    writeAccountToFile(account);
}

void displayAccount(int accountNumber) {
    Account account;
    readAccountFromFile(accountNumber, account);
    account.showAccount();
}

void depositWithdraw(int accountNumber, int option) {
    double amount;
    Account account;
    readAccountFromFile(accountNumber, account);
    
    if (account.getAccountNumber() == accountNumber) {
        account.showAccount();
        
        if (option == 1) {
            cout << "\n\n\tTO DEPOSIT AMOUNT";
            cout << "\n\nEnter The amount to be deposited: ";
            cin >> amount;
            account.deposit(amount);
        } else if (option == 2) {
            cout << "\n\n\tTO WITHDRAW AMOUNT";
            cout << "\n\nEnter The amount to be withdrawn: ";
            cin >> amount;
            
            double balance = account.getBalance();
            if (balance - amount < 0) {
                cout << "Insufficient balance";
                return;
            }
            
            account.withdraw(amount);
        }
        
        modifyAccountInFile(account);
        cout << "\n\n\tRecord Updated";
    }
}

void modifyAccount(int accountNumber) {
    Account account;
    readAccountFromFile(accountNumber, account);
    
    if (account.getAccountNumber() == accountNumber) {
        account.showAccount();
        account.modify();
        modifyAccountInFile(account);
    }
}

void deleteAccount(int accountNumber) {
    deleteAccountFromFile(accountNumber);
}