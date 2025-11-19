#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
using namespace std;

template <typename T>
class LinkedListNode {
public:
    T data;
    LinkedListNode* next;

    LinkedListNode(T value) : data(value), next(nullptr) {}
};
template <typename T>
class LinkedList {
private:
    LinkedListNode<T>* head;
public:
    LinkedList() : head(nullptr) {}

    void insertAtEnd(T value) {
        LinkedListNode<T>* newNode = new LinkedListNode<T>(value);
        if (!head) {
            head = newNode;
            return;
        }
        LinkedListNode<T>* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void insertAtFront(T value) {
        LinkedListNode<T>* newNode = new LinkedListNode<T>(value);
        newNode->next = head;
        head = newNode;
    }

    void display() {
        LinkedListNode<T>* temp = head;
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "nullptr" << endl;
    }
    ~LinkedList() {
        LinkedListNode<T>* current = head;
        LinkedListNode<T>* nextNode;
        while (current) {
            nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }
};
#endif // LINKEDLIST_H
