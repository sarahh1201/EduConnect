#ifndef MATCHING_ALGORITHM_H
#define MATCHING_ALGORITHM_H

#include <iostream>
#include <vector>
#include "../headers/BinarySearchTree.h"
#include "../headers/MinHeapTree.h"

using namespace std;

// One-function matching algorithm
void matchStudentRequest(MinHeap& heap, Node* tutorTree) {
    if (heap.isEmpty()) {
        cout << "No student requests to process.\n";
        return;
    }

    int urgentRequest = heap.peek();
    heap.remove();

    vector<string> subjectsVec = {"Math", "English", "Chemistry", "Biology", "History", "Art"};
    string requestSubject = subjectsVec[urgentRequest % subjectsVec.size()];

    cout << "================= Student Request Match ================\n";
    cout << "Most urgent request ID: " << urgentRequest
         << " (Subject needed: " << requestSubject << ")" << endl;

    // For now, just pick a tutor ID based on request
    int tutorIDtoSearch = 101 + (urgentRequest % 6); // choose one of your existing tutor IDs
    Node* matchedTutor = searchNode(tutorTree, tutorIDtoSearch);

    cout << "Searching for Tutor ID: " << tutorIDtoSearch << "...\n";
    if (matchedTutor)
        cout << "Matched Tutor ID: " << matchedTutor->data
             << " for subject: " << requestSubject << endl;
    else
        cout << "No tutor found for subject: " << requestSubject << endl;
}

#endif
