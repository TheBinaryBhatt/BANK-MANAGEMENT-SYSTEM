// TransactionLogger.cpp
#include "TransactionLogger.h"
#include <fstream>
#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;

void logTransaction(int accountNumber, const string& transactionType, double amount) {
    ofstream logFile("transactions.log", ios::app);
    
    if (!logFile) {
        cerr << "Error opening transaction log file!";
        return;
    }
    
    // Get current time
    time_t now = time(nullptr);
    tm* now_tm = localtime(&now);
    
    char timestamp[20];
    strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", now_tm);
    
    // Write transaction to log
    logFile << "[" << timestamp << "] Account: " << accountNumber 
            << " | Type: " << transactionType 
            << " | Amount: " << fixed << setprecision(2) << amount << endl;
    
    logFile.close();
}