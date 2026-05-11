#ifndef EXPENSE_H
#define EXPENSE_H

#include "Transaction.h"
#include <string>
using namespace std;

class Expense : public Transaction {
private:
    string envelopeName;
public:
    void addExpense(string username);
    void display(string username) override;
};

#endif
