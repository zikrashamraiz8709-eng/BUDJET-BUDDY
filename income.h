#ifndef INCOME_H
#define INCOME_H

#include <string>
using namespace std;

class Income {
private:
    string source;
    double amount;

public:
    // Constructors
    Income();
    // Core Functions
    void addIncome(string username);
    void viewIncome(string username);
    void deleteIncome(string username);
};

#endif
