#include <iostream> // Just a few libraries, I swear
#include <chrono>
#include <thread>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
#include <limits>
#include <cstdio>
#include <unordered_map>
#include "Login_Module.h"
using namespace std;

vector<User> readUsers()
{
	return // Will essentially create the vector as such with the following 3 template users; 2 tutors and 1 student
	{
		User("James", "Cameron", "JCameron", "Where did you grow up?", "Canada", 1),  // Pre-defined users for demonstration purposes
		User("Howard", "Ross", "HRoss", "Name your favourite TV show: ", "Friends", 0),
		User("Philip", "Kindred", "PKindred", "What is your mother's maiden name?", "Joyce", 1)
	};
}

void clearScreen() // For CLI purposes, will wipe the console for the 'windows' used
{
	std::system("cls"); // Literally that's all it does
}

using PassMap = unordered_map<string, string>; // Used to give each user a unique password

PassMap readPassword(const string& path = "server.txt") // For 'security' reasons, the user's passwords should be stored elsewhere
{ // NOTE: This file should either exist in the root of your project, or define its path type. But for the love of God, DO NOT USE A PLAIN TEXT FILE FOR PASSWORD STORAGE IN A REAL BUILD!!!
	PassMap map; // Password 'database'
	string line; // Current line
	ifstream in(path); // Just take its path defined
	if (in.is_open()) // Check that it is in fact, there
	{
		while (getline(in, line))
		{
			if (line.empty() || line[0] == '#') continue; // Ensures the system will go through the whole password list until it exhausts its options.
			auto pos = line.find(':'); // Variable value to detect the split between 'username' and 'password'
			if (pos == string::npos) continue; // If it finds a valid value basically
			string user = line.substr(0, pos); // Isolate user
			string pwd = line.substr(pos + 1); // And the password
			map[user] = pwd; // Will map that user to that password specifically
		}
		in.close(); // Make sure to close the file once done!
		return map;
	}
	else // If you mess up the file placement or whatever
	{
		return map; // Shouldn't return anything for all I care
	}

	return map; // Only triggers if something above somehow critically failed
}

bool writePassword(const PassMap& map, const string& path = "server.txt") // Now going the other way
{ // The 'bool' is literally just to ensure that the file does exist or not
	ofstream out(path, ios::out | ios::trunc); // Note that all data is just truncated together, I see no issue with this totally
	if (out.is_open()) // Check that it is in fact, there
	{
		for (const auto& writePass : map) // How we'll be inserting the password, in pieces
		{
			out << writePass.first << ":" << writePass.second << "\n";
		}
		out.close();
		return true; // This'll return that the password write was successful
	}
	else // If you mess up the file placement or whatever
	{
		return false;
	}

	return false; // Only triggers if something above critically failed
}

bool verify_password(const PassMap& map, const string& username, const string& password) { // Verify the password does exist
	auto it = map.find(username); // First, find the full username string
	if (it == map.end()) // If username doesn't exist, return false
	{
		return false; 
	}
	else // Else, dynamically check if what the user inputted actually matches what's in the 'database'
	{
		return (it->second == password);
	}
}

bool set_password(PassMap& map, const string& username, const string& newPassword, const string& path = "credentials.txt") {
	map[username] = newPassword; // This step solely exists to re-map a user to a new password
	return writePassword(map, path); // Then, actually write the new password
}

void passwordRecovery(const string& user, const string& question, const string& answer, const PassMap& pass) // Asks the user a security question, and if they get it correct present the current password in the 'server'
{
	clearScreen(); // Clear the display for this new 'window'
	cout << "--------------------------------------" << endl;
	cout << "    Educonnect Password Recovery:" << endl;
	cout << "--------------------------------------" << endl;
	cout << "Here is your defined security question " << user << ":" << endl;
	string input; // Just the user's input
	int screwUps = 0; // How long the system will be locked out if you keep mucking it up
	cin.ignore(); // Stops any unnecessary overflow
	while (true)
	{
		cout << question << " ";
		getline(cin, input); // Is able to accept a full line as an answer too
		if (input == answer) // If accepted, show the concurrent password and return
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
			this_thread::sleep_for(chrono::seconds(5));
			return;
		}
		else
		{
			cout << "Incorrect answer." << endl;
			screwUps++;
			if (screwUps == 3) // Forces the user to return back to the password screen without any given password
			{
				cout << "Max incorrect answers reached. Returning to the password screen..." << endl;
				this_thread::sleep_for(chrono::seconds(5));
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


// And now for the main module connecting everything: Password!
void Password(vector<User>& Users, PassMap& pass, const string& path = "server.txt")
{
	vector<string> userID; // Assigns where the usernames are
	vector<string> userQ; // Recollects each user's security question
	vector<string> userA; // And security answer as well
	vector<int> userType;
	
	for (const auto& u : Users) // First, we wanna actually retrieve the data from our user vector
	{
		userID.push_back(u.getUserName()); // For the username,
		userQ.push_back(u.getSecurityQ()); // security question,
		userA.push_back(u.getSecurityA()); // and its answer
		userType.push_back(u.getUserType()); // and its answer
	}

	int numAttempts = 3; // How many times you can muck up the password
	int screwUps = 0; // How long the system will be locked out if you keep mucking it up

	while (true)
	{
		clearScreen(); // Ol' Reliable
		cout << "--------------------------------" << endl;
		cout << "   Educonnect Secure Screen:" << endl;
		cout << "--------------------------------" << endl;

		string ID; // First stage: Get the correct ID
		bool correctID = false; // To make sure if it is the ID that's wrong, or the password if need be
		int type = 0; // Default student assumption
		cout << "User ID: ", cin >> ID;
		cin.clear(); // This is to prevent any other input just randomly being applied to the next time 'cin' is called

		size_t idx = 0; // Now: to index our way through the entire user roster until we find a match
		for (size_t i = 0; i < userID.size(); i++)
		{
			if (ID == userID[i]) // If a User ID is in fact found
			{
				correctID = true; // Return that an ID has been correctly identified
				idx = i; // And set the index position to that user in question
				type = userType[i]; // And to kill two birds with one stone, get their user type here
			}
		}

		if (correctID == false) // If they didn't get it right
		{
			numAttempts--; // Deincrements the attempts every time you muck up
			cout << "Incorrect User ID entered." << endl;
			cout << "Number of attempts remaining: " << numAttempts << endl;
			if (numAttempts == 0)
			{
				screwUps++; // Starts the screw up incrementer
				cout << "System is now locked out for " << (5 * screwUps) << " minutes. If it is incorrect again, another 5 minutes will be added." << endl;
				this_thread::sleep_for(chrono::minutes(5 * screwUps)); // Forces the program to do nothing until this is over
				numAttempts++; // Gives the user one more chance once this time is over.
			}
			this_thread::sleep_for(chrono::seconds(4)); // Small delay
			continue;
		}
		else // Otherwise, they got it right
		{
			cout << "Password: "; // Second Stage: Get the correct password now:
			string password;
			cin >> password; // Same sorta deal
			cin.clear();
			if (password == "recover" || password == "Recover" || password == "RECOVER") // First check: if the user wants to recover their password
			{
				passwordRecovery(ID, userQ[idx], userA[idx], pass); // Run the password recovery program
				continue;
			}
			
			else if (verify_password(pass, ID, password)) // Basically a true/false check whether the password matches
			{ // If this is true, it means the password was correct to that user. Now we need to identify what user type they are:
				if (type == 1) // For the purposes of this program, a user type of value '1' is identified as a Tutor.
				{
					cout << endl << "User is: Tutor" << endl;
					return;
				}
				else // If it's literally anything else, then they're considered a student and should redirect to a 'lite' platform for them
				{						
					cout << endl << "User is: Student" << endl;
					return;
				}
			}

			else // And if neither cases above apply, the password is considered wrong.
			{
				numAttempts--; // Tick them down
				cout << "Incorrect Password entered." << endl;
				cout << "Number of attempts remaining: " << numAttempts << endl;
				if (numAttempts == 0) // Three strikes and you're out basically
				{
					screwUps++; // Begin incrementing the screw up counter
					cout << "System is now locked out for " << (5 * screwUps) << " minutes. If it is incorrect again, another 5 minutes will be added." << endl;
					this_thread::sleep_for(chrono::minutes(5 * screwUps));
					numAttempts = 1; // Once their timeout is over, give them another chance
				}
				this_thread::sleep_for(chrono::seconds(3)); // Helpful tooltip if they've forgotten
				cout << "Forgot your password? Type in 'recover' in the password field, and you can recover the password using a special security question." << endl;
				this_thread::sleep_for(chrono::seconds(5));
				continue;
			}
		}
	}
}

int main()
{
	auto users = readUsers(); // System first reads all 'template' user parameters
	auto pass = readPassword("server.txt"); // System reads the password contents here as well
	Password(users, pass, "server.txt"); // Runs the password client, when complete either go to the Student or Tutor menus depending on what flag condition the user is (Tutor or Student?)
	return 0; // End basic module simulation
}