#include "backend/Decode.h"
#include "backend/Authorization.h"
#include "backend/ClearScreen.h"
#include "backend/BinarySearchTree.h"
#include "backend/RequestHeap.h"
#include "backend/RequestProcess.h"
#include "backend/MakeRequest.h"
#include "backend/CreateAccount.h"
#include "backend/TutorSearch.h"
#include "backend/SessionHistory.h"
#include "backend/AcceptRequest.h"
#include "backend/GiveRating.h"
#include "backend/EditProfile.h"


int main() {
    // Load data from CSV files (can be deleted later if not needed)
    vector<User> users = loadUsersCSV();
    //vector<Tutor> tutors = loadTutorsCSV();
    //vector<Request> requests = loadRequestsCSV();
    //SessionHistory sessions = loadSessionsCSV();
    //vector<string> subjects = loadSubjectsCSV();

    // Debug output to verify loading (can be removed later)
    //cout << "Loaded " << users.size() << " users.\n";
    //cout << "Loaded " << tutors.size() << " tutors.\n";
    //cout << "Loaded " << requests.size() << " requests.\n";
    //cout << "Loaded " << subjects.size() << " subjects.\n";

    
    //SubjectsList(); // Display list of subjects 

    //processRequests(requests, tutors); // Process and match requests to tutors

    //makeAccount(); // Create a new user account (tutor or student)
    //TutorSearchMenu(); // Search for tutors by ID or subject
    //sessions.display(); // Display session history

    //ViewRequests(); // View requests as a tutor
    //AcceptRequest(); // Accept a request as a tutor

    //password(users); // User login and dashboard access

    
    cout << "Welcome to EduConnect!" << endl;
    cout << "Would you like to (1) Login or (2) Create an Account? ";
    int choice;
    cin >> choice;
    cin.ignore(); 
    if (choice == 1) {
        password(users);
    } else if (choice == 2) {
        makeAccount();
    } else {
        cout << "Invalid choice. Exiting." << endl;
    }
    
   //makeAccount();
    //viewTutorProfile("tutor123"); // View tutor profile
    //editProfile("tutor123"); // Edit tutor profile

    return 0;
}


