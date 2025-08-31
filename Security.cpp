// Security.cpp
#include "Security.h"
using namespace std;
// Simple XOR encryption - for demonstration purposes only
// In a real application, use proper encryption like bcrypt
string encryptPassword(const string& password) {
    string encrypted = password;
    char key = 'B'; // Encryption key
    
    for (size_t i = 0; i < encrypted.size(); i++) {
        encrypted[i] ^= key;
    }
    
    return encrypted;
}

bool validatePassword(const string& input, const string& encrypted) {
    return encryptPassword(input) == encrypted;
}