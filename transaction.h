#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
using namespace std;

class Transaction {
protected:
    string name;
    double amount=0.0;
    
public:
    virtual void setTransaction(string n, double a);

    //  PURE VIRTUAL FUNCTION (THIS ENABLES POLYMORPHISM)
    virtual void display(string username) = 0;

    virtual ~Transaction() {}
};

#endif
