#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <string>
using namespace std;


class SessionNode {
    public:
    int sessionID;
    string topic;
    SessionNode* next;

    SessionNode(int id, string t) : sessionID(id), topic(t), next(nullptr) {}
};

class SessionHistory {
public:
    SessionNode* head = nullptr;

    void addSession(int id, string topic) {
        SessionNode* newNode = new SessionNode(id, topic);
        newNode->next = head;
        head = newNode;
    }

    void display() {
        SessionNode* current = head;
        while (current) {
            cout << "Session " << current->sessionID << ": " << current->topic << endl;
            current = current->next;
        }
    }
};
#endif // LINKEDLIST_H