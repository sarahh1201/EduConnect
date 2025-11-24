#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Decode.h"
using namespace std;

void EndSession() {
    int sessionID;
    cout << "Enter Session ID to end: ";
    cin >> sessionID;

    SessionHistory history = loadSessionsCSV();
    SessionNode* current = history.head;
    bool found = false;

    while (current) {
        if (current->data.sessionID == sessionID) {
            current->data.status = "ended";
            found = true;
            break;
        }
        current = current->next;
    }

    if (found) {
        // Save updated sessions back to CSV
        ofstream file(sessionsDataPath);
        if (!file.is_open()) {
            cerr << "Cannot open sessions CSV for writing!\n";
            return;
        }
        file << "sessionID,subject,description,tutorUsername,studentUsername,requestID,status\n";
        SessionNode* curr = history.head;
        while (curr) {
            file << curr->data.sessionID << ","
                 << curr->data.subject << ","
                 << curr->data.description << ","
                 << curr->data.tutorUsername << ","
                 << curr->data.studentUsername << ","
                 << curr->data.requestID << ","
                 << curr->data.status << "\n";
            curr = curr->next;
        }
        file.close();
        cout << "Session " << sessionID << " has been ended successfully.\n";
    } else {
        cout << "Session ID not found.\n";
    }
    
}

void viewActiveSessions(const string& tutorUsername) {
    SessionHistory history = loadSessionsCSV();
    SessionNode* current = history.head;
    bool found = false;

    cout << "Active Sessions for Tutor: " << tutorUsername << endl;
    cout << "----------------------------------------" << endl;

    while (current) {
        if (current->data.tutorUsername == tutorUsername && current->data.status == "accepted") {
            cout << "Session ID: " << current->data.sessionID << endl;
            cout << "Subject: " << current->data.subject << endl;
            cout << "Description: " << current->data.description << endl;
            cout << "Student Username: " << current->data.studentUsername << endl;
            cout << "Request ID: " << current->data.requestID << endl;
            cout << "Status: " << current->data.status << endl;
            cout << "----------------------------------------" << endl;
            found = true;
        }
        current = current->next;
    }

    if (!found) {
        cout << "No active sessions found." << endl;
    }
}