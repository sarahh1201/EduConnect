#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "decode.h"

using namespace std;

// ----------------- User Verification -----------------
User* verifyUser(vector<User>& users, const string& username, const string& password) {
    for (auto& u : users) {
        if (u.username == username && u.password == password)
            return &u;
    }
    return nullptr;
}

// ----------------- Login Screen -----------------
void loginScreen(vector<User>& users) {
    const int maxAttempts = 3;
    int attempts = 0;

    while (attempts < maxAttempts) {
        string userID, password;
        cout << "Enter User ID: ";
        cin >> userID;
        cout << "Enter Password: ";
        cin >> password;

        User* user = verifyUser(users, userID, password);
        if (user) {
            cout << "Login successful! Welcome, " 
                 << user->firstName << " " 
                 << user->lastName << "." << endl;

            if (user->userType == 1)
                cout << "User Type: Tutor" << endl;
            else
                cout << "User Type: Student" << endl;

            return; // Exit after successful login
        } else {
            cout << "Invalid User ID or Password." << endl;
            attempts++;
        }
    }

    cout << "Maximum login attempts reached. Exiting..." << endl;
}