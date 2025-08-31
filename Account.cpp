
#include "Account.h"
#include <iomanip>
using namespace std;

void Account::createAccount() {
    cout << "\nEnter The account No. : ";
    cin >> accountNumber;
    cin.ignore();
    
    cout << "Enter The Name of The account Holder : ";
    cin.getline(name, 50);
    
    cout << "Enter Type of The account (C/S) : ";
    cin >> type;
    type = toupper(type);
    
    cout << "Enter The Initial amount : ";
    cin >> balance;
    
    cout << "\n\nAccount Created..";
}

void Account::showAccount() const {
    cout << "\nAccount Number: " << accountNumber;
    cout << "\nAccount Holder Name: " << name;
    cout << "\nType of Account: " << (type == 'Savings' ? "Savings" : "Current");
    cout << "\nBalance amount: " << fixed << setprecision(2) << balance;
}

void Account::modify() {
    cout << "\nAccount Number: " << accountNumber;
    cout << "\nModify Account Holder Name : ";
    cin.ignore();
    cin.getline(name, 50);
    
    cout << "Modify Type of Account : ";
    cin >> type;
    type = toupper(type);
    
    cout << "Modify Balance amount : ";
    cin >> balance;
}

void Account::deposit(double amount) {
    balance += amount;
}

void Account::withdraw(double amount) {
    if (balance - amount >= 0) {
        balance -= amount;
    } else {
        std::cout << "Insufficient funds!\n";
    }
}


int Account::getAccountNumber() const {
    return accountNumber;
}

double Account::getBalance() const {
    return balance;
}

const char* Account::getName() const {
    return name;
}

char Account::getType() const {
    return type;
}