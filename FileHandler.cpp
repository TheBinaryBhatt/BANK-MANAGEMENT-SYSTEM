// FileHandler.cpp
#include "FileHandler.h"
#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;

const char* DATA_FILE = "accounts.dat";

void writeAccountToFile(const Account& account) {
    ofstream outFile;
    outFile.open(DATA_FILE, ios::binary | ios::app);
    outFile.write(reinterpret_cast<const char*>(&account), sizeof(Account));
    outFile.close();
}

void readAccountFromFile(int accountNumber, Account& account) {
    ifstream inFile;
    inFile.open(DATA_FILE, ios::binary);
    
    if (!inFile) {
        cout << "File could not be opened! Press any Key...";
        return;
    }
    
    bool found = false;
    while (inFile.read(reinterpret_cast<char*>(&account), sizeof(Account))) {
        if (account.getAccountNumber() == accountNumber) {
            found = true;
            break;
        }
    }
    
    inFile.close();
    
    if (!found) {
        cout << "\n\nAccount not found";
    }
}

void modifyAccountInFile(const Account& modifiedAccount) {
    fstream file;
    file.open(DATA_FILE, ios::in | ios::out | ios::binary);
    
    Account account;
    bool found = false;
    
    while (file.read(reinterpret_cast<char*>(&account), sizeof(Account)) && !found) {
        if (account.getAccountNumber() == modifiedAccount.getAccountNumber()) {
            long pos = (-1) * static_cast<long>(sizeof(Account));
            file.seekp(pos, std::ios::cur);
            file.write(reinterpret_cast<const char*>(&modifiedAccount), sizeof(Account));
            found = true;
        }
    }
    
    file.close();
    
    if (!found) {
        cout << "\n\nAccount not found";
    } else {
        cout << "\n\nRecord Updated";
    }
}

void deleteAccountFromFile(int accountNumber) {
    ifstream inFile;
    ofstream outFile;
    
    inFile.open(DATA_FILE, ios::binary);
    if (!inFile) {
        cout << "File could not be opened! Press any Key...";
        return;
    }
    
    outFile.open("Temp.dat", ios::binary);
    inFile.seekg(0, ios::beg);
    
    Account account;
    bool found = false;
    
    while (inFile.read(reinterpret_cast<char*>(&account), sizeof(Account))) {
        if (account.getAccountNumber() != accountNumber) {
            outFile.write(reinterpret_cast<const char*>(&account), sizeof(Account));
        } else {
            found = true;
        }
    }
    
    inFile.close();
    outFile.close();
    
    remove(DATA_FILE);
    rename("Temp.dat", DATA_FILE);
    
    if (found) {
        std::cout << "\n\nRecord Deleted ..";
    } else {
        std::cout << "\n\nAccount not found";
    }
}

void displayAllAccounts() {
    ifstream inFile;
    inFile.open(DATA_FILE, ios::binary);
    
    if (!inFile) {
        cout << "File could not be opened! Press any Key...";
        return;
    }
    
    cout << "\n\n\t\tACCOUNT HOLDER LIST\n\n";
    cout << "====================================================\n";
    cout << "A/c no.      NAME           Type  Balance\n";
    cout << "====================================================\n";
    
    Account account;
    while (inFile.read(reinterpret_cast<char*>(&account), sizeof(Account))) {
        account.showAccount();
        cout << endl;
    }
    
    inFile.close();
}