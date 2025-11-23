#include "backend/decode.h"
#include "backend/auth.h"
#include "backend/clearScreen.h"

int main() {
    vector<User> users = loadUsersCSV("/Users/sarahhill/Documents/Workspaces/Algorithms & Data Structures/EduConnect/v2/data/user.csv");
    vector<Tutor> tutors = loadTutorsCSV("/Users/sarahhill/Documents/Workspaces/Algorithms & Data Structures/EduConnect/v2/data/tutors.csv");
    vector<Request> requests = loadRequestsCSV("/Users/sarahhill/Documents/Workspaces/Algorithms & Data Structures/EduConnect/v2/data/requests.csv");
    SessionHistory sessions = loadSessionsCSV("/Users/sarahhill/Documents/Workspaces/Algorithms & Data Structures/EduConnect/v2/data/sessions.csv");

    cout << "Loaded " << users.size() << " users.\n";
    cout << "Loaded " << tutors.size() << " tutors.\n";
    cout << "Loaded " << requests.size() << " requests.\n";
    cout << "Loaded session history:\n";

    password(users);
    
    sessions.display();

}
