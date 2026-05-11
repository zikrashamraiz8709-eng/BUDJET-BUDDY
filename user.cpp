#include "user.h"
#include <iostream>
#include <fstream>
#include<string>
using namespace std;

// Register
void User::registerUser() {
    cout << "CREATE YOUR USERNAME: ";
    cin >> username;
    
    cout << "CREATE PASSWORD: ";
    cin >> password;

  
    if (username.empty() || password.empty()) {
    cout << "Fields cannot be empty!\n";
       return;
    }

    ifstream checkFile("users.txt");
    string fileUser, filePass;
    while (checkFile >> fileUser >> filePass) {
        if (fileUser == username) {
            cout << "USERNAME ALREADY EXISTS! TRY A DIFFERENT ONE.\n";
            checkFile.close();
            return;

        }
    } checkFile.close();

    ofstream file("users.txt", ios::app);
    if (!file) {
        cout << "ERROR OPENING USERS FILE!\n";
        return;
    }
    file << username << " " << password << endl;
    file.close();

    // Create personal file for this user
    ofstream userFile(username + ".txt");
    userFile.close();

    cout << "\nREGISTRATION SUCCESSFUL!\n";
}

// Login
bool User::loginUser(string u, string p) {
    ifstream file("users.txt");
    if (!file) {
        cout << "ERROR OPENING USERS FILE!\n";
        return false;
    }

    string fileUser, filePass;

    while (file >> fileUser >> filePass) {
        if (fileUser == u && filePass == p ) {
            file.close();
            return true;
        }
    }

    file.close();
    return false;
}