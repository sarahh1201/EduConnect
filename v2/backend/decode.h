#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <string>
#include "SessionHistory.h"
#include "BinarySearchTree.h"
#include "RequestHeap.h"
using namespace std;

string userDataPath = "/Users/sarahhill/Documents/Workspaces/Algorithms & Data Structures/EduConnect/v2/data/user.csv";
string tutorsDataPath = "/Users/sarahhill/Documents/Workspaces/Algorithms & Data Structures/EduConnect/v2/data/tutors.csv";
string requestsDataPath = "/Users/sarahhill/Documents/Workspaces/Algorithms & Data Structures/EduConnect/v2/data/requests.csv";
string sessionsDataPath = "/Users/sarahhill/Documents/Workspaces/Algorithms & Data Structures/EduConnect/v2/data/sessions.csv";
string subjectsDataPath = "/Users/sarahhill/Documents/Workspaces/Algorithms & Data Structures/EduConnect/v2/data/subjects.csv";

// ----------------- User Struct -----------------
struct User {
    string firstName, lastName, username, password, email, securityQ, securityA;
    int userType; // 1 = Tutor, 0 = Student
};

// ----------------- Tutor Struct -----------------
struct Tutor {
    int tutorID;
    string name;
    vector<string> subjects;
    double rating;       
    bool available;
};

// ----------------- Student Request Struct -----------------
struct Request {
    int requestID;
    string studentUsername;
    string subject;
    int urgency;
    string description;
};

// ----------------- CSV User Loaders -----------------
vector<User> loadUsersCSV() {
    vector<User> users;
    ifstream file(userDataPath);
    if (!file.is_open()) { cerr << "Cannot open " << userDataPath << endl; return users; }

    string line; bool firstLine = true;
    while (getline(file, line)) {
        if (firstLine) { firstLine = false; continue; }
        stringstream ss(line);
        User u; string temp;
        getline(ss, u.firstName, ',');
        getline(ss, u.lastName, ',');
        getline(ss, u.username, ',');
        getline(ss, u.password, ',');
        getline(ss, u.email, ',');
        getline(ss, u.securityQ, ',');
        getline(ss, u.securityA, ',');
        getline(ss, temp, ','); u.userType = stoi(temp);
        users.push_back(u);
    }
    return users;
}

void saveUsersCSV(const vector<User>& users) {
    ofstream file(userDataPath, ios::trunc); // Clear + rewrite

    if (!file.is_open()) {
        cerr << "ERROR: Could not open users CSV for writing!" << endl;
        return;
    }

    // Optional: write header
    file << "FirstName,LastName,Username,Password,email,SecurityQ,SecurityA,UserType\n";

    for (const auto& u : users) {
        file << u.username << ","
             << u.firstName << ","
             << u.lastName << ","
             << u.password << ","
             << u.email << ","
             << u.securityQ << ","
             << u.securityA << "\n";
    }

    file.close();
}

// ----------------- CSV Tutor Loaders -----------------
vector<Tutor> loadTutorsCSV() {
    vector<Tutor> tutors;
    ifstream file(tutorsDataPath);
    if (!file.is_open()) { cerr << "Cannot open " << tutorsDataPath << endl; return tutors; }

    string line; bool firstLine = true;
    while (getline(file, line)) {
        if (firstLine) { firstLine = false; continue; }
        stringstream ss(line);
        Tutor t; string subjects;
        string temp;
        getline(ss, temp, ','); t.tutorID = stoi(temp);
        getline(ss, t.name, ',');
        getline(ss, subjects, ',');
        getline(ss, t.email, ',');
        getline(ss, temp, ','); t.rating = stod(temp);
        getline(ss, temp, ','); t.available = (temp == "true");
        stringstream substream(subjects);
        string sub; while(getline(substream, sub, ';')) t.subjects.push_back(sub);
        tutors.push_back(t);
    }
    return tutors;
}

Node* buildTutorTreeFromCSV() {
    vector<Tutor> tutors = loadTutorsCSV(); // loads from CSV
    Node* root = nullptr;

    for (const Tutor& t : tutors) {
        root = insertNode(root, t.tutorID);
    }

    return root;
}

// ----------------- CSV Request Loaders -----------------
vector<Request> loadRequestsCSV() {
    vector<Request> requests;
    ifstream file(requestsDataPath);
    if (!file.is_open()) { cerr << "Cannot open " << requestsDataPath << endl; return requests; }

    string line; bool firstLine = true;
    while (getline(file, line)) {
        if (firstLine) { firstLine = false; continue; }
        stringstream ss(line); Request r; string temp;
        getline(ss, temp, ','); r.requestID = stoi(temp);
        getline(ss, r.studentUsername, ',');
        getline(ss, r.subject, ',');
        getline(ss, temp, ','); r.urgency = stoi(temp);
        getline(ss, r.description, ',');
        requests.push_back(r);
    }
    return requests;
}

void saveRequestsCSV(const vector<Request>& requests) {
    ofstream file(requestsDataPath, ios::trunc); // Clear + rewrite

    if (!file.is_open()) {
        cerr << "ERROR: Could not open requests CSV for writing!" << endl;
        return;
    }

    // Optional: write header
    file << "FirstName,LastName,Username,Password,email,SecurityQ,SecurityA,UserType\n";

    for (const auto& r : requests) {
        file << r.requestID << ","
             << r.studentUsername << ","
             << r.subject << ","
             << r.urgency << ","
             << r.description << "\n";
    }

    file.close();
}

MinHeap* buildRequestHeapFromCSV() {
    vector<Request> requests = loadRequestsCSV(); // loads from CSV
    MinHeap* heap = new MinHeap(100); // assuming max 100 requests

    for (const Request& r : requests) {
        heap->insert(r.requestID); // using requestID as the key
    }

    return heap;
}

// ----------------- CSV Session History Loaders -----------------
SessionHistory loadSessionsCSV() {
    SessionHistory history;
    ifstream file(sessionsDataPath);
    if (!file.is_open()) { cerr << "Cannot open " << sessionsDataPath << endl; return history; }

    string line; bool firstLine = true;
    while (getline(file, line)) {
        if (firstLine) { firstLine = false; continue; }
        stringstream ss(line);
        int id; string topic;
        string temp;
        getline(ss, temp, ','); id = stoi(temp);
        getline(ss, topic, ',');
        history.addSession(id, topic);
    }
    return history;
}

// ----------------- CSV Subject Loaders -----------------
const vector<string> loadSubjectsCSV() {
    vector<string> subjects;
    ifstream file(subjectsDataPath);
    if (!file.is_open()) { cerr << "Cannot open " << subjectsDataPath << endl; return subjects; }

    string line; bool firstLine = true;
    while (getline(file, line)) {
        if (firstLine) { firstLine = false; continue; }
        subjects.push_back(line);
    }
    return subjects;
}

void SubjectsList() {
    vector<string> subjects = loadSubjectsCSV();
    cout << "Available Subjects:\n";
    for (const auto& subject : subjects) {
        cout << "- " << subject << endl;
    }
}

