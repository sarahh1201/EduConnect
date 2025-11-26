#pragma once

#include<iostream>
#include <string>
#include "Decode.h"
#include <vector>
using namespace std;

// Allow tutors to edit their profile information
void editProfile(string username) {
    vector<Tutor> tutors = loadTutorsCSV();
    for (auto &t : tutors)
    {
        if (t.username == username) {
            cout << "Editing profile for " << t.name << " (" << t.username << ")\n";
            cout << "Current Email: " << t.email << "\n";
            cout << "Enter new email (or press enter to keep current): ";
            string newEmail;
            getline(cin, newEmail);
            if (!newEmail.empty()) { // Update only if input is not empty
                t.email = newEmail;
            }

            cout << "Current Subjects: ";
            for (const auto &sub : t.subjects) {
                cout << sub << " ";
            }
            cout << "\nEnter new subjects separated by semicolon (or press enter to keep current): ";
            string newSubjects;
            getline(cin, newSubjects);
            if (!newSubjects.empty()) { // Update only if input is not empty
                t.subjects.clear();
                stringstream ss(newSubjects);
                string subject;
                while (getline(ss, subject, ';')) {
                    t.subjects.push_back(subject);
                }
            }
            cout << "Current Availability: " << (t.available ? "Available" : "Not Available") << "\n";
            cout << "Set availability (1 for Available, 0 for Not Available, or press enter to keep current): ";
            string availabilityInput;
            getline(cin, availabilityInput);
            if (!availabilityInput.empty()) {  // Update only if input is not empty
                t.available = (availabilityInput == "1");
            }
            cout << "Profile updated successfully!\n";
            saveTutorsCSV(tutors);
            break;
        }
    }  
}

void viewTutorProfile(string username) {
    vector<Tutor> tutors = loadTutorsCSV();
    for (const auto &t : tutors)
    {
        if (t.username == username) {
            cout << "Tutor Profile:\n";
            cout << "Name: " << t.name << "\n";
            cout << "Username: " << t.username << "\n";
            cout << "Email: " << t.email << "\n";
            cout << "Subjects: ";
            for (const auto &sub : t.subjects) {
                cout << sub << " ";
            }
            cout << "\nRating: " << t.rating << "\n";
            cout << "Availability: " << (t.available ? "Available" : "Not Available") << "\n";
            break;
        }
    }  
}