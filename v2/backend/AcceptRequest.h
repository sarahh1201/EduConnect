/*#include "Decode.h"
#include <iostream>
using namespace std;

void UpdateRequestStatus(int reqID) {
    vector<Request> requests = loadRequestsCSV();
    removeRequestFromCSV(reqID);

    SessionHistory history;
    for (const auto& r : requests) {
        history.addSession(r.requestID, r.subject, r.description, 0, r.requestID, "accepted");
    }
    saveSessionsCSV(history);
}


void AcceptRequest() {
    Request* req;
    cout << "Enter Request ID to accept: ";
    int reqID;
    cin >> reqID;

    vector<Request> requests = loadRequestsCSV();
    for (const auto& r : requests) {
        if (r.requestID == reqID) {
            req = new Request(r);
            cout << "Request ID " << reqID << " accepted." << endl;
            UpdateRequestStatus(reqID);
        
            // Further processing can be done here
            return;
        }
    }
    cout << "Request ID " << reqID << " not found." << endl;
}

void ViewRequests() {
    vector<Request> requests = loadRequestsCSV();
    cout << "Current Requests:\n";
    for (const auto& req : requests) {
        cout << "Request ID: " << req.requestID
             << " | Student: " << req.studentUsername
             << " | Subject: " << req.subject
             << " | Urgency: " << req.urgency
             << " | Description: " << req.description << endl;
    }
}
*/