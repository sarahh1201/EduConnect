#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Decode.h"
#include "ClearScreen.h"
#include "MakeRequest.h"
#include "TutorSearch.h"
#include "EndSession.h"
#include "GiveRating.h"
#include "EditProfile.h"

#include "AcceptRequest.h"

using namespace std;

void tutorHeader()
{
    clearScreen();
    cout << "--------------------------------" << endl;
    cout << "        Tutor Dashboard" << endl;
    cout << "--------------------------------" << endl;
}

void studentHeader()
{
    clearScreen();
    cout << "--------------------------------" << endl;
    cout << "       Student Dashboard" << endl;
    cout << "--------------------------------" << endl;
}

void TutorDashboard(string tutorUsername)
{
    tutorHeader();

    cout << "Welcome, " << tutorUsername << "!" << endl;
    cout << "Here are the actives requests:" << endl;
    ViewRequests(tutorUsername);


    cout << "1. View Requests" << endl;
    cout << "2. Accept Request" << endl;
    cout << "3. View Active Sessions" << endl;
    cout << "4. End Session" << endl;
    cout << "5. Edit Profile" << endl;
    cout << "6. Logout" << endl;
    cout << "Please select an option: ";

    
    int choice;
    cin >> choice;

    switch (choice)
    {
    case 1:
        ViewRequests(tutorUsername);
        break;
    case 2:
        AcceptRequest(tutorUsername);
        break;
    case 3:
        viewActiveSessions(tutorUsername);
        break;
    case 4:
        EndSession(tutorUsername);
        break;
    case 5:
        editProfile(tutorUsername);
        break;
    case 6:
        cout << "Logging out..." << endl;
        return;
    default:
        cout << "Invalid choice. Please try again." << endl;
    }
}

void StudentDashboard(string studentUsername)
{
    studentHeader();
    cout << "Welcome, " << studentUsername << "!" << endl;

    cout << "1. Make a Request" << endl;
    cout << "2. Search for Tutors" << endl;
    cout << "3. Active Sessions" << endl;
    cout << "4. Give Rating" << endl;
    cout << "5. End Session" << endl;
    cout << "6. Logout" << endl;
    cout << "Please select an option: ";

    int choice;
    cin >> choice;

    switch (choice)
    {
    case 1:
        makeRequest(studentUsername);
        break;
    case 2:
        TutorSearchMenu();
        break;
    case 3:
        viewActiveSessions(studentUsername);
        break;
    case 4:
        GiveRating(studentUsername);
        break;
    case 5:
        EndSession(studentUsername);
    case 6:
        cout << "Logging out..." << endl;
        return;
    default:
        cout << "Invalid choice. Please try again." << endl;
    }

}