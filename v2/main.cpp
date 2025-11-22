#include "backend/decode.h"
#include "backend/auth.h"
#include "backend/clearScreen.h"

int main() {
    vector<User> users = loadUsersCSV("data/user.csv");
    vector<Tutor> tutors = loadTutorsCSV("data/tutors.csv");
    vector<Request> requests = loadRequestsCSV("data/requests.csv");
    SessionHistory sessions = loadSessionsCSV("data/sessions.csv");

    cout << "Loaded " << users.size() << " users.\n";
    cout << "Loaded " << tutors.size() << " tutors.\n";
    cout << "Loaded " << requests.size() << " requests.\n";
    cout << "Loaded session history:\n";

    loginScreen(users);
    
    clearScreen();
    
    sessions.display();
}
