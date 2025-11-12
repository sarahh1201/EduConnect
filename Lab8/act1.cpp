#include <iostream>
#include <string>
#include <queue>
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

int main() {
    string subjects[] = {"Math", "English", "Chemistry", "Biology"};
    string tutorMatches[] = {"Tutor1", "Tutor2", "Tutor3"};

    cout << "Available Subjects:" << endl;
    for (string s : subjects) cout << "- " << s << endl;

    cout << "\nTutor Matches for Student:" << endl;
    for (string t : tutorMatches) cout << "- " << t << endl;


    SessionHistory history;
    history.addSession(1, "Algebra");
    history.addSession(2, "Calculus");
    history.display();

    queue<string> loginQueue;
    loginQueue.push("StudentA");
    loginQueue.push("TutorB");
    loginQueue.push("StudentC");

    cout << "Processing login: " << loginQueue.front() << endl;
    loginQueue.pop();
}
