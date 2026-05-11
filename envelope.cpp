#include "envelope.h"
#include<windows.h>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Constructor
Envelope::Envelope() {
    name = "Unknown";
    budget = 0;
    spent = 0;
}

// Create Envelope
void Envelope::createEnvelope(string username) {
    char choice;
    do {
        cout << "ENTER ENVELOPE NAME: ";
        cin >> name;

        cout << "ENTER BUDGET AMOUNT ";
        cin >> budget;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "INVALID INPUT!\n";
            return;
        }

        if (budget <= 0) {
            cout << "INVALID BUDGET!\n";
            return;
        }

        ofstream file(username + "_envelopes.txt", ios::app);
        file << name << " " << budget <<" "<< 0 << endl;
        file.close();

        cout << "ENVELOPE CREATED SUCCESSFULLY!\n";
        Beep(700, 100);
        Beep(900, 100);
        Beep(1100, 100);
        cout << "\nDO YOU WANT TO ADD ANOTHER ENVELOPE ? (y/n) : ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');
}

// View Envelopes
void Envelope::viewEnvelopes(string username) {
    ifstream file(username + "_envelopes.txt");

    if (!file) {
        cout << "NO ENVELOPE FOUND!\n";
        return;
    }

    string envName;
    double envBudget, envSpent;

    cout << "\n\t\t\t--- YOUR ENVELOPES ---\n";

    while (file >> envName >> envBudget >> envSpent) {
        cout << "\t\tName: " << envName
            << " || Budget: " << envBudget
            << " || Spent: " << envSpent
            << " || Remaining: " << envBudget - envSpent
            << endl;
    }

    file.close();
}

// Fill Envelope
void Envelope::fillEnvelope(string username) {
    string envName;
    double amount;

    cout << "ENTER ENVELOPE NAME : ";
    cin >> envName;

    cout << "ENTER AMOUNT TO ADD : ";
    cin >> amount;

    if (cin.fail()) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "INVALID INPUT!\n";
        return;
    }
    if (amount <= 0) {
        cout << "INVALID AMOUNT!\n";
        return;
    }

    ifstream file(username + "_envelopes.txt");
    string temp = "", name;
    double b, s;
    bool found = false;

    while (file >> name >> b >> s) {
        if (name == envName) {
            b += amount;
            found = true;
        }

        temp += name + " " + to_string(b) + " " + to_string(s) + "\n";
    }

    file.close();

    if (!found) {
        cout << "ENVELOPE NOT FOUND!\n";
        return;
    }

    ofstream out(username + "_envelopes.txt");
    out << temp;
    out.close();

    cout << "AMOUNT ADDED SUCCESSFULLY!\n";
}

// Delete Envelope
void Envelope::deleteEnvelope(string username) {
    string envName;

    cout << "ENTER ENVELOPE NAME TO DELETE : ";
    cin >> envName;

    ifstream file(username + "_envelopes.txt");

    string temp = "", name;
    double b, s;
    bool found = false;

    while (file >> name >> b >> s) {
        if (name == envName) {
            found = true;
            continue;
        }

        temp += name + " " + to_string(b) + " " + to_string(s) + "\n";
    }

    file.close();

    if (!found) {
        cout << "ENVELOPE NOT FOUND!\n";
        return;
    }

    ofstream out(username + "_envelopes.txt");
    out << temp;
    out.close();

    cout << "ENVELOPE DELETED SUCCESSFULLY!\n";
}