// Account.h
#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <cstring>

class Account {
private:
    int accountNumber;
    char name[50];
    char type; // 'S' for Savings, 'C' for Current
    double balance;
    
public:
    void createAccount();
    void showAccount() const;
    void modify();
    void deposit(double amount);
    void withdraw(double amount);
    int getAccountNumber() const;
    double getBalance() const;
    const char* getName() const;
    char getType() const;
};

#endif // ACCOUNT_H