#include <iostream>
#include <fstream>
#include <sstream>
#include "Tutor_Data.h"

using namespace std;

void createCSVTemp() // Exists solely for demonstration purposes in order to create an initial template
{
	ofstream file("Tutor.csv"); // Open the file
	// And some simple row details
	// First, deal with the column format:
	file << "TutorID,First_Name,Last_Name,Email,Rating,Subjects\n";
	file << "101,Philip,Kindred,pkind@gmail.com,4.20,English\n"; // DON'T USE SPACES, IT SCREWS WITH ALL THE READ LOGIC!
	file << "102,James,Cameron,jc@outlook.com,4.56,Math\n";
	file.close(); // Be sure to remember to close it after!
	cout << "Template contents written." << endl;
}

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

int main()
{
	// createCSVTemp(); // Use this operation to create the temp CSV file
	TutorSearchMenu(); // For our use case, we want this to act like a sort of 'Tutor Search' platform to return a Tutor's profile
	return 0;
}