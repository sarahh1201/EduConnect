#ifndef MATCHING_ALGORITHM_H
#define MATCHING_ALGORITHM_H

#include <iostream>
#include <vector>
#include <unordered_map>
#include "BinarySearchTree.h"
#include "MinHeapTree.h"
#include "decode.h"

using namespace std;

// Rotate subjects based on integer request
static vector<string> SUBJECT_LIST = {
    "Math", "English", "Chemistry", "Biology", "History", "Art"
};

// Map subjects to tutor IDs (simulating relational database)
static unordered_map<string, vector<int>> subjectToTutors = {
    {"Math",        {101, 105}},
    {"English",     {102}},
    {"Chemistry",   {}},
    {"Biology",     {104}},
    {"History",     {106}},
    {"Art",         {107}}
};

void matchStudentRequest(MinHeap& heap, Node* tutorTree) {
    if (heap.isEmpty()) {
        cout << "No student requests pending.\n";
        return;
    }

    int urgencyValue = heap.pop_val();

    // Convert integer → Request struct
    Request urgentRequest;
    urgentRequest.requestID = urgencyValue;
    urgentRequest.urgency = urgencyValue;
    urgentRequest.subject = SUBJECT_LIST[urgencyValue % SUBJECT_LIST.size()];

    cout << "\n=============== Matching Student Request ===============\n";
    cout << "Request ID: " << urgentRequest.requestID
         << " | Subject: " << urgentRequest.subject
         << " | Urgency: " << urgentRequest.urgency << endl;

    vector<int> possibleTutors = subjectToTutors[urgentRequest.subject];

    // List the available tutors for the subject in the system. 
    cout << "Tutors offering " << urgentRequest.subject << ": ";
    for (int id : possibleTutors) cout << id << " ";
    cout << "\n";

    // Match with the first available tutor in the BST
    Node* matchedTutor = nullptr;
    for (int id : possibleTutors) {
        matchedTutor = searchNode(tutorTree, id);
        if (matchedTutor) break;
    }

    if (matchedTutor) {
        cout << "Matched Tutor ID: " << matchedTutor->data << endl;
        cout << "Request " << urgentRequest.requestID << " assigned successfully.\n";
    } else {
        cout << "No available tutors found for this request.\n";
    }
}

#endif
