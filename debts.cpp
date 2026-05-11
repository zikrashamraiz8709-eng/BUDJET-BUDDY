#include "debt.h"
#include <iostream>
#include <fstream>
using namespace std;

// Add Debt
void Debt::addDebt(string username) {
    char choice;

    do {
        cout << "\nENTER DEBT SOURCE (e.g. Friend/Loan): ";
        cin >> name;

        cout << "ENTER DEBT AMOUNT: ";
        cin >> amount;

        if (cin.fail() || amount <= 0) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "INVALID AMOUNT!\n";
            return;
        }


        ofstream file(username + "_debt.txt", ios::app);
        if (!file) {
            cout << "ERROR OPENING FILE!\n";
            return;
        }

        file << name << " " << amount << endl;
        file.close();

        cout << "DEBT ADDED SUCCESSFULLY!\n";

        cout << "ADD MORE DEBT? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');
}
void Debt::display(string username) {

    ifstream file(username + "_debt.txt");

    if (!file) {
        cout << "NO DEBT FOUND!\n";
        return;
    }

    string source;
    double amt;
    double total = 0;
    cout << "\n--- YOUR DEBT ---\n";

    while (file >> source >> amt) {
        cout << "SOURCE: " << source
            << " | AMOUNT: " << amt << endl;
        total += amt;
    }

    cout << "TOTAL DEBT: " << total<< endl;

    file.close();
}
void Debt::payDebt(string username) {

    string target;
    double payAmount;

    cout << "ENTER DEBT SOURCE TO PAY: ";
    cin >> target;

    cout << "ENTER AMOUNT TO PAY: ";
    cin >> payAmount;

    if (cin.fail() || payAmount <= 0) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "INVALID AMOUNT!\n";
        return;
    }

   

    ifstream file(username + "_debt.txt");

    if (!file) {
        cout << "NO DEBT FILE FOUND!\n";
        return;
    }

    string source;
    double amt;
    string temp = "";
    bool found = false;

    while (file >> source >> amt) {

        if (source == target) {
            amt -= payAmount;

            if (amt < 0)
                amt = 0;

            found = true;
        }

        temp += source + " " + to_string(amt) + "\n";
    }

    file.close();

    if (!found) {
        cout << "DEBT NOT FOUND!\n";
        return;
    }

    ofstream out(username + "_debt.txt");
    if (!out) {
        cout << "ERROR UPDATING FILE!\n";
        return;
    }

    out << temp;
    out.close();

    cout << "DEBT PAYMENT UPDATED!\n";
}