#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "decode.h"
#include "clearScreen.h"

using namespace std;

// ----------------- User Verification -----------------
User* verifyUser(vector<User>& users, const string& username, const string& password) {
    for (auto& u : users) {
        if (u.username == username && u.password == password)
            return &u;
    }
    return nullptr;
}

// ----------------- Login Screen -----------------
void loginScreen(vector<User>& users) {
    const int maxAttempts = 3;
    int attempts = 0;

    while (attempts < maxAttempts) {
        string userID, password;
        cout << "Enter User ID: ";
        cin >> userID;
        cout << "Enter Password: ";
        cin >> password;

        // Recovery
        if (password =="recover"){
            passwordRecovery(userID);
        }

        User* user = verifyUser(users, userID, password);
        if (user) {
            cout << "Login successful! Welcome, " 
                 << user->firstName << " " 
                 << user->lastName << "." << endl;

            if (user->userType == 1)
                cout << "User Type: Tutor" << endl;
            else
                cout << "User Type: Student" << endl;

            return; // Exit after successful login
        } else {
            cout << "Invalid User ID or Password." << endl;
            attempts++;
        }
    }

    cout << "Maximum login attempts reached. Exiting..." << endl;
}

void passwordRecovery(const string& user) // Asks the user a security question, and if they get it correct present the current password in the 'server'
{
	clearScreen(); // Clear the display for this new 'window'
	cout << "--------------------------------------" << endl;
	cout << "    Educonnect Password Recovery:" << endl;
	cout << "--------------------------------------" << endl;
	cout << "Here is your defined security question " << user->securityQ << ":" << endl;
	string input; // Just the user's input
    int screwUps = 0; // How long the system will be locked out if you keep mucking it up
	cin.ignore(); // Stops any unnecessary overflow
	while (true)
	{
		cout << question << " ";
		getline(cin, input); // Is able to accept a full line as an answer too
		if (input == securityA) // If accepted, show the concurrent password and return
		{
			cout << "Answer accepted." << endl;
			auto item = pass.find(user); // Find the user's password
			if (item != pass.end()) // If found within the file basically
			{
				cout << "Your password is " << item->second << endl; // Second item is their password here
			}
			else // If it fails to find the password
			{
				cout << "Either no password is set for this user, or the server cannot be reached." << endl;
			}
			return;
		}
		else
		{
			cout << "Incorrect answer." << endl;
			if (screwUps == 3) // Forces the user to return back to the password screen without any given password
			{
				cout << "Max incorrect answers reached. Please try again later" << endl;
				return;
			}
			cout << "Number of attempts remaining: " << (3 - screwUps) << endl;
		}
	}
}

void PasswordChanger(const vector<User>& Users, PassMap& pass, const string& passwordFile = "server.txt") // Does exactly what's on the tin
{ // NOTE: This function is currently unused, be sure to have an option for the user to change their password when logged in!
	clearScreen(); // Clear way for this cool new window!
	cout << "--------------------------------" << endl;
	cout << "   Educonnect Password Changer" << endl;
	cout << "--------------------------------" << endl;
	cout << "User ID: "; // First, ask the user to re-input their ID once more for verification
	string ID;
	cin >> ID; // Quite aptly
	cin.clear(); // This is to prevent any other input just randomly being applied to the next time 'cin' is called

	const User* matchedUser = nullptr; // First, find if this user they inputted does in fact, exist
	for (const auto& u : Users) if (u.getUserName() == ID) // Should be able to check all users
	{
		matchedUser = &u; // When found, we'll be using their credidentials to reset their password
		break;
	}
	else // When no user has been found under this regard
	{
		cout << "Unknown User ID. Returning to main menu..." << endl;
		this_thread::sleep_for(chrono::seconds(2));
	}

	int screwUps = 0; // Now for the password stage, and for everyone's favourite variable, the screw up counter!
	string oldPassword; // Let this represent the old password the user will be inputting
	while (true)
	{
		cout << "To verify; please type in the old password prior: ";
		cin >> oldPassword;
		if (verify_password(pass, ID, oldPassword)) // Runs a true/false check. When true, the user can input their new password here
		{
			cout << "Password accepted." << endl;
			cout << "Now please enter the new password you wish to overwrite the prior one: ";
			string newPassword; // And now let the user write their new password
			cin >> newPassword;
			cin.clear();
			if (set_password(pass, ID, newPassword, passwordFile)) // Do effectively another true/false check on the password being written
			{
				cout << "Password has been saved to the company server." << endl;
			}
			else // If it fails for whatever reason
			{
				cout << "Error: Unable to write to the credentials file." << endl;
			}
		}
		else // If the user messes up putting their password in
		{
			cout << "Incorrect password." << endl;
			screwUps++; // User only gets 3 chances before they're booted outta here
			cout << "Number of attempts remaining: " << (3 - screwUps) << endl;
			if (screwUps == 3) // Once the threshold is hit, kick them back to the menu
			{
				cout << "Returning to the main menu..." << endl;
				this_thread::sleep_for(chrono::seconds(3));
				return;
			}
			this_thread::sleep_for(chrono::seconds(3));
		}
	}
}