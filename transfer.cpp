#include "transfer.h"
#include <windows.h>
#include <iostream>
#include <fstream>
using namespace std;

void Transfer::transferMoney(string username) {

    string fromEnv, toEnv;

    cout << "ENTER FROM ENVELOPE: ";
    cin >> fromEnv;

    cout << "ENTER TO ENVELOPE: ";
    cin >> toEnv;

    cout << "ENTER AMOUNT TO TRANSFER: ";
    cin >> amount;

    if (amount <= 0) {
        cout << "AMOUNT MUST BE GREATER THAN 0!\n";
        Beep(300, 500);
        return;
    }

    ifstream file(username + "_envelopes.txt");

    if (!file) {
        cout << "ENVELOPE FILE NOT FOUND!\n";
        return;
    }

    double budget, spent;

    string temp = "";

    bool foundFrom = false, foundTo = false;
    bool canTransfer = false;

    double fromAvailable = 0;

    // FIRST PASS: check availability
    while (file >> name >> budget >> spent) {

        if (name == fromEnv) {
            fromAvailable = budget - spent;

            if (fromAvailable >= amount) {
                canTransfer = true;
                foundFrom = true;
            }
            else {
                cout << "NOT ENOUGH MONEY IN " << fromEnv << endl;
                file.close();
                return;
            }
        }
    }

    file.close();

    if (!canTransfer) return;

    // SECOND PASS: update file
    ifstream file2(username + "_envelopes.txt");

    while (file2 >> name >> budget >> spent) {

        if (name == fromEnv) {
            budget -= amount;
            foundFrom = true;
        }

        if (name == toEnv) {
            budget += amount;
            foundTo = true;
        }

        temp += name + " " + to_string(budget) + " " + to_string(spent) + "\n";
    }

    file2.close();

    if (!foundTo) {
        cout << "DESTINATION ENVELOPE NOT FOUND!\n";
        return;
    }

    ofstream out(username + "_envelopes.txt");
    out << temp;
    out.close();

    cout << "TRANSFER SUCCESSFUL!\n";
    Beep(1000, 150);
    Beep(1200, 150);
   
}
void Transfer::display(string username)
    {
        cout << "\n--- TRANSFER MODULE ---\n";
        cout << "TRANSFERS ARE SYSTEM OPERATIONS THAT MOVES FUND BETWEEN ENVELOPES !\n";
    }