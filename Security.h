// Security.h
#ifndef SECURITY_H
#define SECURITY_H

#include <string>
using namespace std;
string encryptPassword(const string& password);
bool validatePassword(const string& input, const string& encrypted);

#endif