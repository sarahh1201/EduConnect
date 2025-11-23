#include "backend/Decode.h"
#include "backend/auth.h"
#include "backend/clearScreen.h"
#include "backend/BinarySearchTree.h"
#include "backend/RequestHeap.h"
#include "backend/RequestAlgorithm.h"


int main() {

    // Load data from CSV files
    vector<User> users = loadUsersCSV();
    vector<Tutor> tutors = loadTutorsCSV();
    vector<Request> requests = loadRequestsCSV();
    SessionHistory sessions = loadSessionsCSV();
    vector<string> subjects = loadSubjectsCSV();

    cout << "Loaded " << users.size() << " users.\n";
    cout << "Loaded " << tutors.size() << " tutors.\n";
    cout << "Loaded " << requests.size() << " requests.\n";
    cout << "Loaded " << subjects.size() << " subjects.\n";
    cout << "Loaded session history:\n";
    clearScreen_verify();
    //password(users);
    
    sessions.display();
    SubjectsList();

    processRequests(requests, tutors);

}
