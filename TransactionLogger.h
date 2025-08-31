// TransactionLogger.h
#ifndef TRANSACTIONLOGGER_H
#define TRANSACTIONLOGGER_H
#include <string>
using namespace std;

void logTransaction(int accountNumber, const string& transactionType, double amount);

#endif