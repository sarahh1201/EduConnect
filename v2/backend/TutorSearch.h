#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <cctype>
#include "clearScreen.h"

using namespace std;

void TutorSearchMenu()
{
	clearScreen(); // Assuming the user will access this from a separate window, clear the prior one
	cout << "--------------------------------" << endl;
	cout << "      Tutor Search Wizard" << endl;
	cout << "--------------------------------" << endl;
	cout << "Please select which method you want to search for your tutor(s):" << endl;
	cout << "1. By the Tutor's ID" << endl;
	cout << "2. By the Tutor's Name" << endl;
	cout << "3. By Subject" << endl;
	cout << "4. By Rating Threshold" << endl;
	cout << "Option: ";
	int input = 0; // Let the user select which variation they want to search for a tutor
	cin >> input;
	cin.clear(); // As usual, prevent any input carrying into another
	switch (input)
	{
		case 1: // Selected Tutor ID search method
		{
			SearchTutorID();
			break;
		}
		case 2: // Selected the subject search method
		{
			SearchTutorName();
			break;
		}
		case 3: // Selected finding tutors by a minimum rating threshold
		{
			SearchSubject();
			break;
		}
		case 4: // Selected finding tutors by a minimum rating threshold
		{
			MinTutorRating();
			break;
		}
		default: // If an invalid input has been given:
		{
			cout << "Error: Invalid input entered." << endl;
		}
	}
}

// I didn't really need to implement any classes for this, so the header file just stores all the searching algorithms
// Saves space on the main space, sorta.

void SearchTutorID()
{
	clearScreen(); // Re-wipe the screen
	cout << "--------------------------------" << endl;
	cout << "      Tutor Search Wizard" << endl;
	cout << "--------------------------------" << endl;
	cout << "Please input which tutor ID you wish to retrieve:" << endl;
	cout << "Tutor ID #";
	int input = 0;
	bool verifier = false; // Just ensures if there is in fact a Tutor ID that matches
	cin >> input;
	cin.clear(); // As usual, prevent any input carrying into another

	// Now for the CSV manipulation:
	vector<string> row; // Get a CSV row
	string line, word, temp; // And its elements
	int TutorID; // Need to get this value out of the table
	ifstream file("Tutor.csv"); // Open the file accordingly
	if (file.is_open()) // Ensures the file does in fact, exist
	{
		while (getline(file, line)) // So long as there's still data to pull
		{
			// Redeclare these to a default state after every line
			vector<string> row; // Vector for all the row elements, pretty simple
			stringstream part(line); // Takes the full compilation of characters from a cell
			string cell; // As it says on the tin

			if (line.empty()) // If the current line is completely empty, end these checks
			{
				continue;
			}

			while (getline(part, cell, ','))  // And for any element found, we put it into the subsequent vector
			{
				row.push_back(cell);
			}

			try // This will attempt to run this operation. Given that the initial column defs will make this fail since its a string into an integer, it will fallback onto the 'catch' case.
			{
				TutorID = stoi(row[0]); // stoi = String To Integer for the Tutor ID's, we assign the table value to a variable
			}
			catch (...) // In that instance, just ignore the row in question and move on.
			{
				continue;
			}

			if (input == TutorID) // And we compare if they match. If so, we return the tutor's details
			{
				cout << endl << "Tutor #" << row[0] << endl;
				cout << "--------------------------------" << endl;
				cout << "Name: " << row[1] << " " << row[2] << endl;
				cout << "Subject Taught: " << row[5] << endl;
				cout << "Rating: " << row[4] << endl;
				cout << "Email: " << row[3] << endl;
				verifier = true;
				break; // Will end immediately after since it's the Tutor ID and there should only be one unique value. Should save computation time, compared to other methods.
			}
		}
		if (verifier == false) // If still false
		{
			cout << "No Tutor exists under this ID." << endl;
		}
		file.close(); // Don't forget to close the file when you're done with it!
	}
	else // If the file cannot be located
	{
		cout << "Error: File database not found." << endl;
	}
}

void SearchSubject() // All the other search algorithms are some modification of the ID one, with some caveats:
{
	clearScreen(); // Re-wipe the screen
	cout << "--------------------------------" << endl;
	cout << "      Tutor Search Wizard" << endl;
	cout << "--------------------------------" << endl;
	cout << "Please select which subject you wish to see tutors for:" << endl;
	cout << "1. Math" << endl; // To prevent weird user inputs, use pre-fixed options the user chooses from
	cout << "2. English" << endl; // For more subjects, just keep extending the case-switch operation. Simple!
	cout << "Option: ";
	int input = 0; // Chooses which subject the user wants to see tutors for 
	bool verifier = false; // Still exists just in case no tutors exist for a given course, somehow
	string Subject; // The subject the user wants via the options provided
	cin >> input;
	cin.clear(); // As usual, prevent any input carrying into another
	switch (input)
	{
		case 1:
		{
			Subject = "Math"; // Directly assigns our subject to be found to be the same format as used in the CSV file
			break;
		}
	
		case 2:
		{
			Subject = "English"; // Directly assigns our subject to be found to be the same format as used in the CSV file
			break;
		}
		default: // Same default checker
		{
			cout << "Error: Invalid input entered." << endl;
			break;
		}
	}
	cout << endl << "Selected Subject: " << Subject << endl; // Just segments the subject chosen and tutors to be printed
	cout << "--------------------------------" << endl;

	// Now for the CSV manipulation:
	vector<string> row; // Get a CSV row
	string line, word, temp; // And its elements
	string tableSubject; // This time, we need to find a subject
	ifstream file("Tutor.csv"); // Open the file accordingly
	if (file.is_open()) // Ensures the file does in fact, exist
	{
		while (getline(file, line)) // So long as there's still data to pull
		{
			// Redeclare these to a default state after every line
			vector<string> row; // Vector for all the row elements, pretty simple
			stringstream part(line); // Takes the full compilation of characters from a cell
			string cell; // As it says on the tin

			if (line.empty()) // If the current line is completely empty, end these checks
			{
				continue;
			}

			while (getline(part, cell, ','))  // And for any element found, we put it into the subsequent vector
			{
				row.push_back(cell);
			}

			try // This will just attempt to run it, if it fails then it will move to the fallback case
			{
				tableSubject = row[5]; // Assign our derived subject as a variable to compare
			}
			catch (...) // In that instance, just ignore the row in question.
			{
				continue;
			}
			if (Subject == tableSubject) // And we compare if they match. If so, we return the tutor's details
			{
				cout << endl << "Tutor #" << row[0] << endl;
				cout << "----------" << endl;
				cout << "Name: " << row[1] << " " << row[2] << endl;
				cout << "Rating: " << row[4] << endl;
				cout << "Email: " << row[3] << endl;
				verifier = true;
				continue; // Since multiple tutors can teach one subject, this function should run until it reaches the end of the table, retrieving every valid tutor as well.
			}
		}
		if (verifier == false) // If still false
		{
			cout << "No Tutor exists under this subject." << endl;
		}
		file.close(); // Don't forget to close the file when you're done with it!
	}
	else // If the file cannot be located
	{
		cout << "Error: File database not found." << endl;
	}
}

void SearchTutorName() // All the other search algorithms are some modification of the ID one, with some caveats:
{
	clearScreen(); // Re-wipe the screen
	cout << "--------------------------------" << endl;
	cout << "      Tutor Search Wizard" << endl;
	cout << "--------------------------------" << endl;
	cout << "Please input what tutor name you desire:" << endl;
	cout << "Name: "; // This time, we want this to be able to retrieve either a first name or last name
	string input; // Chooses which subject the user wants to see tutors for 
	bool verifier = false; // Still exists in the event no tutors exist for a given name input
	cin >> input;
	cin.clear(); // As usual, prevent any input carrying into another

	cout << endl << "Selected Tutor(s): " << endl; // Just segments the name chosen and tutors to be printed
	cout << "--------------------------------" << endl;

	// Now for the CSV manipulation:
	vector<string> row; // Get a CSV row
	string line, word, temp; // And its elements
	string firstName; // We will retrieve two things to compare, the first name
	string lastName; // and their last name
	ifstream file("Tutor.csv"); // Open the file accordingly
	if (file.is_open()) // Ensures the file does in fact, exist
	{
		while (getline(file, line)) // So long as there's still data to pull
		{
			// Redeclare these to a default state after every line
			vector<string> row; // Vector for all the row elements, pretty simple
			stringstream part(line); // Takes the full compilation of characters from a cell
			string cell; // As it says on the tin

			if (line.empty()) // If the current line is completely empty, end these checks
			{
				continue;
			}

			while (getline(part, cell, ','))  // And for any element found, we put it into the subsequent vector
			{
				row.push_back(cell);
			}

			try // This will just attempt to run it, if it fails then it will move to the fallback case
			{
				firstName = row[1]; // Assign the first name accordingly
				lastName = row[2];
			}
			catch (...) // In that instance, just ignore the row in question.
			{
				continue;
			}
			if (input == firstName || input == lastName || input == (firstName + " " + lastName)) // We go through all three cases of what a user can input to find a tutor's name
			{
				cout << endl << "Tutor #" << row[0] << endl;
				cout << "----------" << endl;
				cout << "Name: " << row[1] << " " << row[2] << endl;
				cout << "Subject Taught: " << row[5] << endl;
				cout << "Rating: " << row[4] << endl;
				cout << "Email: " << row[3] << endl;
				verifier = true;
				continue; // Since multiple tutors could share a name, this function should run until it reaches the end of the table, retrieving every valid tutor as well.
			}
		}
		if (verifier == false) // If still false
		{
			cout << "No Tutor exists under this name." << endl;
		}
		file.close(); // Don't forget to close the file when you're done with it!
	}
	else // If the file cannot be located
	{
		cout << "Error: File database not found." << endl;
	}
}

void MinTutorRating() // All the other search algorithms are some modification of the ID one, with some caveats:
{
	clearScreen(); // Re-wipe the screen
	cout << "--------------------------------" << endl;
	cout << "      Tutor Search Wizard" << endl;
	cout << "--------------------------------" << endl;
	cout << "Please input what minimum rating you desire for a tutor:" << endl;
	cout << "Min. Rating Threshold: ";
	double input = 0; // Allow decimal values to be used!
	bool verifier = false; // Just ensures if there is a tutor that can meet the threshold
	cin >> input;
	cin.clear(); // As usual, prevent any input carrying into another
	cout << endl << "Selected Tutor(s): " << endl; // Just segments the rating piece and tutors to be printed
	cout << "--------------------------------" << endl;

	// Now for the CSV manipulation:
	vector<string> row; // Get a CSV row
	string line, word, temp; // And its elements
	double Rating; // Need to get this value out of the table
	ifstream file("Tutor.csv"); // Open the file accordingly
	if (file.is_open()) // Ensures the file does in fact, exist
	{
		while (getline(file, line)) // So long as there's still data to pull
		{
			// Redeclare these to a default state after every line
			vector<string> row; // Vector for all the row elements, pretty simple
			stringstream part(line); // Takes the full compilation of characters from a cell
			string cell; // As it says on the tin

			if (line.empty()) // If the current line is completely empty, end these checks
			{
				continue;
			}

			while (getline(part, cell, ','))  // And for any element found, we put it into the subsequent vector
			{
				row.push_back(cell);
			}

			try // This will attempt to run this operation. Given that the initial column defs will make this fail since its a string into an integer, it will fallback onto the 'catch' case.
			{
				Rating = stod(row[4]); // stod = String To Double for ratings, we assign the table value to a variable
			}
			catch (...) // In that instance, just ignore the row in question and move on.
			{
				continue;
			}

			if (input <= Rating) // So long as a tutor's rating is equal or greater than what the user inputted, display them
			{
				cout << endl << "Tutor #" << row[0] << endl;
				cout << "----------" << endl;
				cout << "Name: " << row[1] << " " << row[2] << endl;
				cout << "Subject Taught: " << row[5] << endl;
				cout << "Rating: " << row[4] << endl;
				cout << "Email: " << row[3] << endl;
				verifier = true;
				continue; // Since multiple tutors will likely fall under a rating threshold, they should all be displayed.
			}
		}
		if (verifier == false) // If still false
		{
			cout << "No Tutor exists for this rating threshold." << endl;
		}
		file.close(); // Don't forget to close the file when you're done with it!
	}
	else // If the file cannot be located
	{
		cout << "Error: File database not found." << endl;
	}
}