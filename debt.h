#ifndef DEBT_H
#define DEBT_H

#include "transaction.h"
#include <string>
using namespace std;

class Debt : public Transaction {
public:
    void addDebt(string username);
    void display(string username) override;
    void payDebt(string username);   
};

#endif
