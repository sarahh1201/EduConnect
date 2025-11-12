#include <iostream>
#include "BinarySearchTree.h"
using namespace std;

int main()
{
    // Example for a basic implementation of EduConnect Tutor Priorities with a Binary Search Tree
    // Suppose we want to use such a tree to organize student request priorities:


    Node* st_pr = nullptr; // We create the tree and some placeholder values, with least = highest priority
    st_pr = insertNode(st_pr, 10);
    st_pr = insertNode(st_pr, 5);
    st_pr = insertNode(st_pr, 8);
    st_pr = insertNode(st_pr, 3);
    st_pr = insertNode(st_pr, 9);
    st_pr = insertNode(st_pr, 4);
    st_pr = insertNode(st_pr, 12);

    // If the tutor wants to retrieve a particular priority value
    Node* found = searchNode(st_pr, 10);

    if (found != nullptr) 
    {
        cout << "Priority #10 found in the BST." << endl;
        cout << "Metadata about the priority value would be placed here." << endl;
    }
    else 
    {
        cout << "Priority #10 is not found in the BST." << endl;
    }

    // If a priority needs to be deleted, either at the discretion of the tutor, or when the request is fulfilled:
    st_pr = deleteNode(st_pr, 10);

    cout << "Priority #10 has been deleted." << endl;

    // Check now that the node has been in fact, deleted:
    found = searchNode(st_pr, 10);

    if (found != nullptr)
    {
        cout << "Priority #10 found in the BST." << endl;
        cout << "Metadata about the priority value would be placed here." << endl;
    }
    else
    {
        cout << "Priority #10 is not found in the BST." << endl;
    }

    // And most importantly: How to get the most urgent priority to the given tutor as quick as possible:
    Node* min = minValueNode(st_pr);

    cout << "Most urgent priority: #" << min->data << endl;

    return 0;
}
