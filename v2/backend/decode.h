#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <string>
#include "SessionHistory.h"
#include "BinarySearchTree.h"
#include "MinHeapTree.h"
using namespace std;

// ----------------- User Struct -----------------
struct User {
    string firstName, lastName, username, password, securityQ, securityA;
    int userType; // 1 = Tutor, 0 = Student
};

// ----------------- Tutor Struct -----------------
struct Tutor {
    int tutorID;
    string name;
    vector<string> subjects;
};

// ----------------- Student Request Struct -----------------
struct Request {
    int requestID;
    string studentUsername;
    string subject;
    int urgency;
};

// ----------------- CSV Loaders -----------------
vector<User> loadUsersCSV(const string& path) {
    vector<User> users;
    ifstream file(path);
    if (!file.is_open()) { cerr << "Cannot open " << path << endl; return users; }

    string line; bool firstLine = true;
    while (getline(file, line)) {
        if (firstLine) { firstLine = false; continue; }
        stringstream ss(line);
        User u; string temp;
        getline(ss, u.firstName, ',');
        getline(ss, u.lastName, ',');
        getline(ss, u.username, ',');
        getline(ss, u.password, ',');
        getline(ss, u.securityQ, ',');
        getline(ss, u.securityA, ',');
        getline(ss, temp, ','); u.userType = stoi(temp);
        users.push_back(u);
    }
    return users;
}

vector<Tutor> loadTutorsCSV(const string& path) {
    vector<Tutor> tutors;
    ifstream file(path);
    if (!file.is_open()) { cerr << "Cannot open " << path << endl; return tutors; }

    string line; bool firstLine = true;
    while (getline(file, line)) {
        if (firstLine) { firstLine = false; continue; }
        stringstream ss(line);
        Tutor t; string subjects;
        string temp;
        getline(ss, temp, ','); t.tutorID = stoi(temp);
        getline(ss, t.name, ',');
        getline(ss, subjects, ',');
        stringstream substream(subjects);
        string sub; while(getline(substream, sub, ';')) t.subjects.push_back(sub);
        tutors.push_back(t);
    }
    return tutors;
}

vector<Request> loadRequestsCSV(const string& path) {
    vector<Request> requests;
    ifstream file(path);
    if (!file.is_open()) { cerr << "Cannot open " << path << endl; return requests; }

    string line; bool firstLine = true;
    while (getline(file, line)) {
        if (firstLine) { firstLine = false; continue; }
        stringstream ss(line); Request r; string temp;
        getline(ss, temp, ','); r.requestID = stoi(temp);
        getline(ss, r.studentUsername, ',');
        getline(ss, r.subject, ',');
        getline(ss, temp, ','); r.urgency = stoi(temp);
        requests.push_back(r);
    }
    return requests;
}

SessionHistory loadSessionsCSV(const string& path) {
    SessionHistory history;
    ifstream file(path);
    if (!file.is_open()) { cerr << "Cannot open " << path << endl; return history; }

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
