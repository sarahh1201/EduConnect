#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include "LinkedList.h"
#include "BinarySearchTree.h"
#include "MinHeapTree.h"
using namespace std;

int main() {
    cout << "===== EduConnect Simplified System =====" << endl;

    // Arrays: Subjects and Tutors
    string subjects[] = {"Math", "English", "Chemistry", "Biology"};
    string tutorMatches[] = {"Tutor1", "Tutor2", "Tutor3"};

    cout << "\nAvailable Subjects:" << endl;
    for (string s : subjects) cout << "- " << s << endl;

    cout << "\nTutor Matches for Student:" << endl;
    for (string t : tutorMatches) cout << "- " << t << endl;

    // Binary Search Tree: Tutors by ID
    cout << "\n===== Binary Search Tree: Tutor Directory =====" << endl;
    int tutorIDs[] = {103, 101, 105, 109};
    Node* tutorTree = nullptr;
    for (int id : tutorIDs) tutorTree = insertNode(tutorTree, id);
   
    cout << "In-order traversal of Tutor IDs (sorted): ";
    inOrderTraversal(tutorTree);
    cout << endl;
Node* found = searchNode(tutorTree, tutorIDs[0]); // Searching for tutor ID 103
    if (found)
        cout << "Tutor ID #" << tutorIDs[0] << " found in system." << endl;
    else
        cout << "Tutor ID #" << tutorIDs[0] << " not found." << endl;

Node* found2 = searchNode(tutorTree, 102); // Searching for tutor ID 109
    if (found2)
        cout << "Tutor ID #" << 102 << " found in system." << endl;
    else
        cout << "Tutor ID #" << 102 << " not found." << endl;
    

    // MinHeap: Student Request Queue
    cout << "\n===== Min Heap: Student Request Queue =====" << endl;
    MinHeap minHeap(6);
    vector<int> requests = {5, 2, 7, 1, 3};
    minHeap.buildHeap(requests);

    cout << "Current heap (lower = more urgent): ";
    minHeap.print();

    cout << "Most urgent request ID: #" << minHeap.peek() << endl;
    minHeap.insert(0);
    cout << "\nNew urgent request (0) added." << endl;
    cout << "Updated heap: ";
    minHeap.print();
    cout << "Most urgent request ID: #" << minHeap.peek() << endl;

    // QUEUE: Login Requests
    cout << "\n===== Queue: Login Processing =====" << endl;
    queue<string> loginQueue;
    loginQueue.push("Student_A");
    loginQueue.push("Tutor_B");
    loginQueue.push("Student_C");

    while (!loginQueue.empty()) {
        cout << "Processing login for: " << loginQueue.front() << endl;
        loginQueue.pop();
    }

    // Linked List: Session History
    cout << "\n===== Linked List: Tutoring Session History =====" << endl;
    SessionHistory history;
    history.addSession(1, "Algebra");
    history.addSession(2, "English Grammar");
    history.addSession(3, "Chemistry Review");

    history.display();
    return 0;
}