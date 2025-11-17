#include <iostream>
#include <vector>
#include "MatchingAlgorithm.h"
#include "../headers/MinHeapTree.h"
#include "../headers/BinarySearchTree.h"

using namespace std;

int main() {
    // Build MinHeap with student requests
    MinHeap minHeap(10);
    vector<int> studentRequests = {12, 3, 7, 1, 9, 4};
    minHeap.buildHeap(studentRequests);

    cout << "Initial Student Request Heap: ";
    minHeap.print();
    cout << endl;

    // Build tutor BST
    Node* tutorTree = nullptr;
    int tutorIDs[] = {101, 103, 105, 107, 109, 111};
    for (int id : tutorIDs) {
        tutorTree = insertNode(tutorTree, id);
    }

    cout << "\nTutor IDs in BST (in-order traversal): ";
    inOrderTraversal(tutorTree);
    cout << endl << endl;

    // Match students to tutors
    matchStudentRequest(minHeap, tutorTree);
    matchStudentRequest(minHeap, tutorTree);
    matchStudentRequest(minHeap, tutorTree);
    matchStudentRequest(minHeap, tutorTree);
    matchStudentRequest(minHeap, tutorTree);

    return 0;
}
