#include "income.h"
#include <iostream>
#include <fstream>
using namespace std;

// Constructor
Income::Income() {
    source= "Unknown";
    amount = 0;
}
// Add Income
void Income::addIncome(string username) {
    char choice;
    do {
        cout << "Enter THE SOURCE OF INCOME : ";
        cin.ignore(1000, '\n');
        getline(cin, source);

        if (source.empty()) {
            cout << "INVALID SOURCE!\n";
            return;
        }

        cout << "Enter INCOME EARNED BY THE SOURCE : ";
        cin >> amount;
        if (cin.fail() || amount <= 0) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "INVALID AMOUNT!\n";
            return;
        }

        ofstream file(username + "_income.txt", ios::app);
        if (!file) {
            cout << "ERROR OPENING FILE!\n";
            return;
        }

        file << source << " " << amount << endl;
        file.close();

        cout << "INCOME ADDED SUCCESSFULLY!\n";
        cout << "\nDO YOU WANT TO ADD ANOTHER INCOME ? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');
}
// View INCOME
void Income::viewIncome(string username) {
    ifstream file(username + "_income.txt");

    if (!file) {
        cout << "No Income Found!\n";
        return;
    }

    string incSour;
    double incAmount;
    double total = 0;
    cout << "\n\n\t\t\t--- YOUR INCOME ---\n";

    while (file >> incSour >> incAmount) {
        
        cout << "\n\t\t\tSOURCE: " << incSour << "\n\t\t\tAMOUNT : " << incAmount   << endl;
        total += incAmount;
    }
    cout << "TOTAL INCOME : " << total;
    file.close();
}

void Income::deleteIncome(string username) {
    string deleteSource;

    cout << "Enter Income Source to Delete: ";
    cin.ignore(1000, '\n');
    getline(cin, deleteSource);

    ifstream file(username + "_income.txt");

    if (!file) {
        cout << "No Income Found!\n";
        return;
    }

    string src;
    double amt;
    string temp = "";
    bool found = false;

    while (file >> src >> amt) {
        if (src == deleteSource) {
            found = true;
            continue; // skip deleting record
        }

        temp += src + " " + to_string(amt) + "\n";
    }

    file.close();

    if (!found) {
        cout << "INCOME SOURCE NOT FOUND!\n";
        return;
    }

    ofstream out(username + "_income.txt");

    if (!out) {
        cout << "ERROR UPDATING FILE!\n";
        return;
    }
    out << temp;
    out.close();

    cout << "INCOME DELETED SUCCESSFULLY!\n";
}