#include "savings.h"
#include<windows.h>
#include <iostream>
#include <fstream>
using namespace std;

// Add Savings
void Savings::addSavings(string username) {
    char choice;
    string name;
    int amount;

    do {
        cout << "\nENTER SAVINGS PURPOSE: ";
        cin >> name;

        cout << "ENTER AMOUNT: ";
        cin >> amount;

        if (amount <= 0) {
            cout << "INVALID AMOUNT!\n";
            return;
        }

        ofstream file(username + "_savings.txt", ios::app);
        file << name << " " << amount << endl;
        file.close();

        cout << "SAVINGS ADDED SUCCESSFULLY!\n";
        Beep(800, 200);

        cout << "ADD MORE SAVINGS? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');
}

// View Savings
void Savings::viewSavings(string username) {

    ifstream file(username + "_savings.txt");

    if (!file) {
        cout << "NO SAVINGS FOUND!\n";
        return;
    }

    string purpose;
    double amt;
    double total = 0;

    cout << "\n--- YOUR SAVINGS ---\n";

    while (file >> purpose >> amt) {
        cout << "PURPOSE: " << purpose
            << " | AMOUNT: " << amt << endl;
        total += amt;
    }

    cout << "TOTAL SAVINGS: " << total<< endl;

    file.close();
}

