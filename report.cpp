#include "report.h"
#include <iostream>
#include <fstream>
using namespace std;

void Report::showSummary(string username) {

    double totalIncome = 0;
    double totalExpense = 0;
    double totalSavings = 0;
    double totalDebt = 0;

    string name;
    double amount;

    // ----------- INCOME -----------
    ifstream incomeFile(username + "_income.txt");
    while (incomeFile >> name >> amount) {
        totalIncome += amount;
    }
    incomeFile.close();

    // ----------- EXPENSE -----------
    string env;
    ifstream expenseFile(username + "_expenses.txt");
    while (expenseFile >> name >> amount >> env) {
        totalExpense += amount;
    }
    expenseFile.close();

    // ----------- SAVINGS -----------
    ifstream savingsFile(username + "_savings.txt");
    while (savingsFile >> name >> amount) {
        totalSavings += amount;
    }
    savingsFile.close();

    // ----------- DEBT -----------
    ifstream debtFile(username + "_debt.txt");
    while (debtFile >> name >> amount) {
        totalDebt += amount;
    }
    debtFile.close();

    // ----------- FINAL BALANCE -----------
    double balance = totalIncome - totalExpense - totalSavings - totalDebt;

    // ----------- OUTPUT -----------
    cout << "\n\n\t\t====== FINANCIAL REPORT ======\n";

    cout << "\n\t\tTOTAL INCOME   : " << totalIncome;
    cout << "\n\t\tTOTAL EXPENSE  : " << totalExpense;
    cout << "\n\t\tTOTAL SAVINGS  : " << totalSavings;
    cout << "\n\t\tTOTAL DEBT     : " << totalDebt;

    cout << "\n\t\t-----------------------------";
    cout << "\n\t\tFINAL BALANCE  : " << balance << endl;

    if (balance > 0)
        cout << "\t\tSTATUS: GOOD (Saving Money)\n";
    else if (balance < 0)
        cout << "\t\tSTATUS: WARNING (Overspending!)\n";
    else
        cout << "\t\tSTATUS: BALANCED\n";
}