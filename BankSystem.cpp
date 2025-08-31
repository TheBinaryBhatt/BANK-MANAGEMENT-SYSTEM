// Updated BankSystem.cpp with enhanced features
#include "BankSystem.h"
#include "BankOperations.h"
#include "FileHandler.h"
#include "TransactionLogger.h"
#include "Security.h"
#include <iostream>
#include <cstdlib>
#include <limits>
#include <fstream>
using namespace std;

// Store encrypted password (in real app, this would be in a secure storage)
const string ENCRYPTED_ADMIN_PASSWORD = encryptPassword("admin123");

void displayMenu() {
    cout << "\n\n\n\tBANK MANAGEMENT SYSTEM";
    cout << "\n\n\tMAIN MENU";
    cout << "\n\n\t01. NEW ACCOUNT";
    cout << "\n\n\t02. DEPOSIT AMOUNT";
    cout << "\n\n\t03. WITHDRAW AMOUNT";
    cout << "\n\n\t04. BALANCE ENQUIRY";
    cout << "\n\n\t05. MODIFY AN ACCOUNT";
    cout << "\n\n\t06. CLOSE AN ACCOUNT";
    cout << "\n\n\t07. VIEW ALL ACCOUNTS (Admin)";
    cout << "\n\n\t08. VIEW TRANSACTION HISTORY (Admin)";
    cout << "\n\n\t09. EXPORT ACCOUNTS TO CSV (Admin)";
    cout << "\n\n\t10. EXIT";
    cout << "\n\n\tSelect Your Option (1-10): ";
}

bool adminLogin() {
    string password;
    cout << "\n\n\tEnter Admin Password: ";
    cin >> password;
    
    return validatePassword(password, ENCRYPTED_ADMIN_PASSWORD);
}

void exportToCSV() {
    // Implementation for exporting accounts to CSV
    ifstream inFile;
    ofstream csvFile;
    
    inFile.open("accounts.dat", ios::binary);
    csvFile.open("accounts.csv");
    
    if (!inFile || !csvFile) {
        cout << "Error opening files!";
        return;
    }
    
    // Write CSV header
    csvFile << "AccountNumber,Name,Type,Balance\n";
    
    Account account;
    while (inFile.read(reinterpret_cast<char*>(&account), sizeof(Account))) {
        csvFile << account.getAccountNumber() << ","
                << account.getName() << ","
                << account.getType() << ","
                << account.getBalance() << "\n";
    }
    
    inFile.close();
    csvFile.close();
    
    cout << "\n\nAccounts exported to accounts.csv successfully!";
}

int main() {
    char ch;
    int num;
    
    do {
        system("clear"); // Use "cls" for Windows
        displayMenu();
        
        cin >> ch;
        system("clear");
        
        switch(ch) {
            case '1':
                createAccount();
                break;
            case '2':
                num = getAccountNumber();
                depositWithdraw(num, 1);
                logTransaction(num, "DEPOSIT", 0); // Amount would be captured in the function
                break;
            case '3':
                num = getAccountNumber();
                depositWithdraw(num, 2);
                logTransaction(num, "WITHDRAWAL", 0); // Amount would be captured in the function
                break;
            case '4':
                num = getAccountNumber();
                displayAccount(num);
                break;
            case '5':
                num = getAccountNumber();
                modifyAccount(num);
                break;
            case '6':
                num = getAccountNumber();
                deleteAccount(num);
                break;
            case '7':
                if (adminLogin()) {
                    displayAllAccounts();
                } else {
                    cout << "\n\n\tAccess Denied!";
                }
                break;
            case '8':
                if (adminLogin()) {
                    // Display transaction history
                    system("cat transactions.log"); // Use "type" for Windows
                } else {
                    cout << "\n\n\tAccess Denied!";
                }
                break;
            case '9':
                if (adminLogin()) {
                    exportToCSV();
                } else {
                    cout << "\n\n\tAccess Denied!";
                }
                break;
            case '10':
                cout << "\n\n\tThanks for using bank management system";
                break;
            default:
                cout << "\a";
        }
        
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.get();
        
    } while(ch != '10');
    
    return 0;
}