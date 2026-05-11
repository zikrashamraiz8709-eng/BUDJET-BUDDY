#include "history.h"
#include <iostream>
#include <fstream>
using namespace std;

// Set data
double amount; string date;
void History::setData(string from, string to, double amt, string d) {
    fromEnvelope = from;
    toWhere = to;
    amount = amt;
    date = d;
}

// Save record to file
void History::record(string username) {

    ofstream file(username + "_history.txt", ios::app);

    file << "FROM: " << fromEnvelope
        << " | TO: " << toWhere
        << " | AMOUNT: " << amount
        << " | DATE: " << date << endl;

    file.close();
}

// View history
void History::viewHistory(string username) {

    ifstream file(username + "_history.txt");

    if (!file) {
        cout << "NO HISTORY FOUND!\n";
        return;
    }

    string line;

    cout << "\n--- TRANSACTION HISTORY ---\n";

    while (getline(file, line)) {
        cout << line << endl;
    }

    file.close();
}