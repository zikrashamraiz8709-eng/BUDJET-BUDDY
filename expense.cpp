#include <iostream>
#include<windows.h>
#include <fstream>
#include "expense.h"
#include "history.h" 
using namespace std;

void Expense::addExpense(string username) {

    string envName;
    double envBudget, envSpent;
    string temp = "";
    bool found = false;
    cout << "\n--- Available Envelopes ---\n";

    ifstream file(username + "_envelopes.txt");
   
    if (!file) {
        cout << "NO ENVELOPES FOUND!\n";
        return;
    }
    double budget, spent;

    while (file >> envName >> budget >> spent) {
        cout << "- " << envName << endl;
    }

    file.close();

    cout << "\nEnter Envelope Name: ";
    cin>> envelopeName;


    if (envelopeName == "")
    {
        cout << "Envelope name not set!\n";
        return;
    }
    // Take expense details
    cout << "ENTER EXPENSE NAME: ";
    cin >> name;

    cout << "ENTER EXPENSE AMOUNT: ";
    cin >> amount;

    if (amount <= 0) {
        cout << "AMOUNT MUST BE GREATER THAN 0!\n";
        Beep(300, 500);
        return;
    }

    string date;
    cout << "ENTER DATE (DD-MM-YYYY): ";
    cin >> date;


    // Re-open envelope file for updating spent
    ifstream readFile(username + "_envelopes.txt");
    string target = envelopeName;
  
    while (readFile >> envName >> envBudget >> envSpent) {

        string current = envName;

        if (current == target) {
             found = true;
             // CHECK BUDGET LIMIT
             if (envSpent + amount > envBudget) {
                 cout << "INSUFFICIENT ENVELOPE BUDGET!\n";
                 readFile.close();
                 return;
             }

            envSpent += amount;
           
        }

        temp += envName + " " +
            to_string(envBudget) + " " +
            to_string(envSpent) + "\n";
    }

    readFile.close();

    if (!found) {
        cout << "Envelope not found!\n";
        return;
    }

    ofstream writeFile(username + "_envelopes.txt");
    if (!writeFile) {
        cout << "ERROR UPDATING ENVELOPE FILE!\n";
        return;
    }
    writeFile << temp;
    writeFile.close();


    // Save expense in expense file
    ofstream expFile(username + "_expenses.txt", ios::app);
    if (!expFile) {
        cout << "ERROR SAVING EXPENSE!\n";
        return;
    }
    expFile << name << " " << amount << " " << envelopeName << endl;
    expFile.close();
    
    History h;
    h.setData(envelopeName, name, amount, date);
    h.record(username);

    cout << "Expense added & envelope updated successfully!\n";
    Beep(800, 200);
}

void Expense::display(string username)
{
    ifstream file(username + "_expenses.txt");

    if (!file) {
        cout << "N0 EXPENSES FOUND!\n";
        return;
    }
    string expName, envName;
    double amt;

    while (file >> expName >> amt >> envName) {
        cout << expName << " " << amt << " " << envName << endl;
    }
}