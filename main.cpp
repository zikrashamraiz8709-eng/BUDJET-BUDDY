#include<iostream>
#include <windows.h>
#include "user.h"
#include "envelope.h"
#include "income.h"
#include "expense.h"
#include "savings.h"
#include "debt.h"
#include "report.h"
#include"transfer.h"
#include"history.h"
using namespace std;
int main() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED| FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    cout << "\t\t\t ____            _            _   ____            _     _       \n";
    cout << "\t\t\t| __ ) _   _  __| | __ _  ___| |_| __ ) _   _  __| | __| |_   _ \n";
    cout << "\t\t\t|  _ \\| | | |/ _` |/ _` |/ _ \\ __|  _ \\| | | |/ _` |/ _` | | | |\n";
    cout << "\t\t\t| |_) | |_| | (_| | (_| |  __/ |_| |_) | |_| | (_| | (_| | |_| |\n";
    cout << "\t\t\t|____/ \\__,_|\\__,_|\\__, |\\___|\\__|____/ \\__,_|\\__,_|\\__,_|\\__, |\n";
    cout << "\t\t\t                    |___/                                  |___/ \n";
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    cout << "\n\t\t\t  -----------------------------------------------------------" << endl;
    cout << "\t\t\t  | WELCOME TO 'BUDGET BUDDY' YOUR PERSONAL EXPENSE TRACKER |";
    cout << "\n\t\t\t  -----------------------------------------------------------" << endl;
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    cout << "\t\t\t\t  _____________________________________________ \n";
    cout << "\t\t\t\t /                                             \\ \n";
    cout << "\t\t\t\t|                  DASHBOARD                    |\n";
    cout << "\t\t\t\t \\_____________________________________________/ \n";
    cout << "\t\t\t\t  _____________________________________________ \n";

    // Main Content Area
    cout << "\t\t\t\t |                                             | \n";
    cout << "\t\t\t\t |        1. USER REGISTRATION                 | \n";
    cout << "\t\t\t\t |        2. USER LOGIN                        | \n";
    cout << "\t\t\t\t |        3. CREATE ENVELOPE                   | \n";
    cout << "\t\t\t\t |        4. VIEW ENVELOPES                    | \n";
    cout << "\t\t\t\t |        5. FILL ENVELOPE                     | \n";
    cout << "\t\t\t\t |        6. DELETE ENVELOPE                   | \n";
    cout << "\t\t\t\t |        7. ADD INCOMES                       | \n";
    cout << "\t\t\t\t |        8. VEIW INCOMES AND TOTAL            | \n";
    cout << "\t\t\t\t |        9. DELETE INCOME                     | \n";
    cout << "\t\t\t\t |        10. ADD EXPENSE                      | \n";
    cout << "\t\t\t\t |        11. VEIW EXPENSE                     | \n";
    cout << "\t\t\t\t |        12. ADD SAVINGS                      | \n";
    cout << "\t\t\t\t |        13. VEIW SAVINGS                     | \n";
    cout << "\t\t\t\t |        14. ADD DEBT                         | \n";
    cout << "\t\t\t\t |        15. VEIW DEBT                        | \n";
    cout << "\t\t\t\t |        16. PAY DEPT                         | \n";
    cout << "\t\t\t\t |        17. SHOW REPORT                      | \n";
    cout << "\t\t\t\t |        18. TRANSFER MONEY                   | \n";
    cout << "\t\t\t\t |        19. VEIW TRANSACTIONS HISTORY        | \n";
    cout << "\t\t\t\t |        20. LOGOUT                           | \n";
    cout << "\t\t\t\t |        21. EXIT                             | \n";
    cout << "\t\t\t\t |_____________________________________________| \n";
    
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    User u1;
    Envelope env1;
    Income inc;
    Expense exp;
    Savings s;
    Debt d;
    Report r;
    Transaction* t = nullptr;
    Transfer tr;
    History h;
    int choice;
    bool isLoggedIn = false;
    string u, p, e;

    do {
        cout << "\n\n>> Select Your Financial Move: ";
        cin >> choice;
    
         if (cin.fail()) {  // WRONG INPUT? 
            cin.clear();   // FIX THE ERROR
            cin.ignore(1000, '\n');  // REMOVE BAD INPUT
            cout << "INVALID! ENTER A NUMBER.\n";
            continue;  // ASK AGAIN
        }
        switch (choice) {

        case 1:
            u1.registerUser();
            break;

        case 2:
            if (isLoggedIn) {
                cout << "A USER IS ALREADY LOGGED IN (" << u << "). PLEASE LOGOUT FIRST!\n";
            }
            else {
                cout << "ENTER USERNAME : ";
                cin >> u;
                cout << "Enter PASSWORD : ";
                cin >> p;

                if (u1.loginUser(u, p)) {
                    cout << "LOGIN SUCCESSFUL!\n";
                    Beep(800, 200);
                    isLoggedIn = true;
                }
                else {
                    cout << "INVALID CREDENTIALS!\n";
                    Beep(300, 500);
                    u = ""; // clear if failed
                }
            }
            break;
        case 3:
            if (isLoggedIn)
                env1.createEnvelope(u);
            else
                cout << "PLEASE LOGIN FIRST!\n";
            break;

        case 4:
            if (isLoggedIn)
                env1.viewEnvelopes(u);
            else
                cout << "PLEASE LOGIN FIRST!\n";
            break;

        case 5:
            if (isLoggedIn)
                env1.fillEnvelope(u);
            else
                cout << "PLEASE LOGIN FIRST!\n";
            break;

        case 6:
            if (isLoggedIn)
                env1.deleteEnvelope(u);
            else
                cout << "PLEASE LOGIN FIRST!\n";
            break;

        case 7:
            if (isLoggedIn)
                inc.addIncome(u);
            else
                cout << "PLEASE LOGIN FIRST!\n";
            break;

        case 8:
            if (isLoggedIn)
                inc.viewIncome(u);
            else
                cout << "PLEASE LOGIN FIRST!\n";
            break;

        case 9:
            if (isLoggedIn)
                inc.deleteIncome(u);
            else
                cout << "PLEASE LOGIN FIRST!\n";
            break;
        case 10:
            if (isLoggedIn)
                exp.addExpense(u);
            else
                cout << "PLEASE LOGIN FIRST!\n";
            break;
        case 11:
            if (isLoggedIn) {
                if (t != nullptr) {
                    delete t;
                    t = nullptr;
                }
                t = new Expense();
                t->display(u);
            }
            else
                cout << "PLEASE LOGIN FIRST!\n";
            break;
        case 12:
            if (isLoggedIn)
                s.addSavings(u);
            else
                cout << "PLEASE LOGIN FIRST!\n";
            break;
        case 13:
            if (isLoggedIn)
                s.viewSavings(u);
            else
                cout << "PLEASE LOGIN FIRST!\n";
            break;
        case 14:
            if (isLoggedIn)
                d.addDebt(u);
            
            else
                cout << "PLEASE LOGIN FIRST!\n";
            break;
        case 15:
            if (isLoggedIn) {
                if (t != nullptr) {
                    delete t;
                    t = nullptr;
                }
                t = new Debt();
                t->display(u);
            }
            else
                cout << "PLEASE LOGIN FIRST!\n";
            break;
        case 16:
            if (isLoggedIn)
                d.payDebt(u);
            else
                cout << "PLEASE LOGIN FIRST!\n";
            break;
        case 17:
            if (isLoggedIn)
                r.showSummary(u);
            else
                cout << "PLEASE LOGIN FIRST!\n";
            break;
        case 18:
            if (isLoggedIn) {
                if (t != nullptr) {
                    delete t;
                    t = nullptr;
                }
                tr.transferMoney(u);
                t = new Transfer();
                t->display(u);
            }
            else
                cout << "PLEASE LOGIN FIRST!\n";
            break;
        case 19:
            if (isLoggedIn)
                h.viewHistory(u);
            else
                cout << "PLEASE LOGIN FIRST!\n";
            break;
        case 20:
           // Logout
            if (isLoggedIn) {
                cout << "LOGGED OUT SUCCESSFULLY!\n";
                isLoggedIn = false;
                u = "";   // clear username
            }
            else {
                cout << "NO USER LOGGED IN!\n";
            }
            break;
        case 21:
            cout << "PROGRAM ENDED"<<endl;
            break;
        default:
            cout << "INVALID CHOICE! PLEASE SELECT A VALID OPTION.\n";
            break;
        }
    } while (choice != 21);
    if (t != nullptr)
        delete t;

    return 0;
}
