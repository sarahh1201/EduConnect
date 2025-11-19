#include <iostream>
#include "../headers/MinHeapTree.h"
#include "../headers/BinarySearchTree.h"
#include "MatchingAlgorithm.h"

using namespace std;

int main() {
    Node* tutorTree = nullptr;
    vector<int> tutorIDs = {101, 102, 104, 105};
    for (int id : tutorIDs) {
        tutorTree = insertNode(tutorTree, id);
    }
    cout << "Tutor BST created.\n";

    cout << "Create MinHeap for student requests.\n";
    MinHeap requestHeap(10);

    cout << "Adding student requests...\n";
    requestHeap.insert(5);   
    requestHeap.insert(2);   
    requestHeap.insert(11);  
    requestHeap.insert(3);
    requestHeap.insert(1);
    requestHeap.insert(0);
    cout << "Requests added to MinHeap.\n";

    cout << "\n--- Running Match #1 ---\n";
    matchStudentRequest(requestHeap, tutorTree);

    cout << "\n--- Running Match #2 ---\n";
    matchStudentRequest(requestHeap, tutorTree);

    cout << "\n--- Running Match #3 ---\n";
    matchStudentRequest(requestHeap, tutorTree);

    cout << "\n--- Running Match #4 ---\n";
    matchStudentRequest(requestHeap, tutorTree);

    cout << "\n--- Running Match #5 ---\n";
    matchStudentRequest(requestHeap, tutorTree);

    return 0;
}
