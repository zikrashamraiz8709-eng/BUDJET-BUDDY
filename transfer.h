#ifndef TRANSFER_H
#define TRANSFER_H
#include "Transaction.h"
#include <string>
using namespace std;

class Transfer : public Transaction {
public:
    void transferMoney(string username);
    virtual void display(string username) override;
};

#endif
