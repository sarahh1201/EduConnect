#include <iostream>
#include <vector>
#include <string>
#include "Decode.h"
using namespace std;

void addTutorAccount(User* user) {
    Tutor newTutor;
    cout << "Assigning Tutor ID..." << endl;
    vector<Tutor> tutors = loadTutorsCSV();
    newTutor.tutorID = tutors.empty() ? 1 : tutors.back().tutorID + 1;  

    cout << "Enter subjects you can teach (separated by semicolons, ex. English;Math;Science): ";
    cin.ignore();
    string subjectsLine;
    getline(cin, subjectsLine);

    // Split subjects by ';'
    stringstream ss(subjectsLine);
    string sub;
    while (getline(ss, sub, ';')) {
        newTutor.subjects.push_back(sub);
    }

    // Append new tutor to CSV
    ofstream file(tutorsDataPath, ios::app);
    if (!file.is_open()) {
        cerr << "ERROR: Could not open tutors CSV for appending!" << endl;
        return;
    }

    // Join subjects back into a single string with ';'
    string subjectsCSV;
    for (size_t i = 0; i < newTutor.subjects.size(); i++) {
        subjectsCSV += newTutor.subjects[i];
        if (i < newTutor.subjects.size() - 1) subjectsCSV += ";";
    }

    file << newTutor.tutorID << ","
         << (user->firstName + " " + user->lastName) << ","
         << subjectsCSV << ","
         << user->email << ","
         << "0.0" << ","  // initial rating
         << "true" << "\n"; // initially available
    file.close();

    cout << "New tutor account successfully created." << endl;
}


void makeAccount() {
    User newUser;
    cout << "Enter your first name: ";
    cin >> newUser.firstName;
    cout << "Enter your last name: ";
    cin >> newUser.lastName;
    cout << "Enter desired username: ";
    cin >> newUser.username;
    cout << "Enter desired password: ";
    cin >> newUser.password;
    cout << "Enter your email: ";
    cin >> newUser.email;

    string questionChoice[] = {
        "Where did you grow up?",
        "Name your favourite TV show",
        "What is your mother's maiden name?",
        "What was your first pet's name?"
    };

    cout << "Select a security question:" << endl;
    for (size_t i = 0; i < sizeof(questionChoice)/sizeof(questionChoice[0]); i++) {
        cout << i + 1 << ") " << questionChoice[i] << endl;
    }
    int qChoice;
    cin >> qChoice;

    cin.ignore(); // clear newline character from buffer
    newUser.securityQ = questionChoice[qChoice - 1];

    cout << "Enter the answer to your security question: ";
    getline(cin, newUser.securityA);
    cout << "Student or Tutor? (0 = Student, 1 = Tutor): ";
    cin >> newUser.userType;
    
    if (newUser.userType == 1) {addTutorAccount(&newUser);}    

    // Append new request to CSV
    ofstream file(userDataPath, ios::app);
    if (!file.is_open()) {
        cerr << "ERROR: Could not open users CSV for appending!" << endl;
        return;
    }

    file << newUser.username << ","
         << newUser.firstName << ","
         << newUser.lastName << ","
         << newUser.password << ","
         << newUser.email << ","
         << newUser.securityQ << ","
         << newUser.securityA << ","
         << newUser.userType << "\n";
    file.close();
    cout << "New user successfully created." << endl;
}
