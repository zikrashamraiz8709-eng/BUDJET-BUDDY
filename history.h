#ifndef HISTORY_H
#define HISTORY_H
#include "transaction.h"
#include <string>
using namespace std;

class History {
private:
    string fromEnvelope;
    string toWhere;

public:
    void setData(string from, string to, double amt, string d);
    void record(string username);
    void viewHistory(string username);
};

#endif
