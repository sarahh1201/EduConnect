#include "Decode.h"
#include "SessionHistory.h"
#include <iostream>
using namespace std;

void UpdateRequestStatus(int reqID)
{
    vector<Request> requests = loadRequestsCSV();

    // Find the request
    auto it = find_if(requests.begin(), requests.end(),
                      [reqID](const Request &r)
                      { return r.requestID == reqID; });
    if (it == requests.end())
    {
        cout << "Request ID not found." << endl;
        return;
    }
    Request acceptedRequest = *it;

    // Remove request from CSV
    removeRequestFromCSV(reqID);

    // Load existing sessions, add new session
    SessionHistory history = loadSessionsCSV();
    Session newSession{
        acceptedRequest.requestID,   // sessionID
        acceptedRequest.subject,     // subject
        acceptedRequest.description, // description
        0,                           // tutorID (can assign later)
        acceptedRequest.requestID,   // requestID
        "accepted"                   // status
    };
    history.addSession(newSession);

    // Save updated sessions
    saveSessionsCSV(history);

    cout << "Request " << reqID << " accepted and session created.\n";
}

void AcceptRequest()
{
    Request *req;
    cout << "Enter Request ID to accept: ";
    int reqID;
    cin >> reqID;

    vector<Request> requests = loadRequestsCSV();
    for (const auto &r : requests)
    {
        if (r.requestID == reqID)
        {
            req = new Request(r);
            cout << "Request ID " << reqID << " accepted." << endl;
            UpdateRequestStatus(reqID);

            // Further processing can be done here
            return;
        }
    }
    cout << "Request ID " << reqID << " not found." << endl;
}

void ViewRequests()
{
    vector<Request> requests = loadRequestsCSV();
    cout << "Current Requests:\n";
    for (const auto &req : requests)
    {
        cout << "Request ID: " << req.requestID
             << " | Student: " << req.studentUsername
             << " | Subject: " << req.subject
             << " | Urgency: " << req.urgency
             << " | Description: " << req.description << endl;
    }
}
