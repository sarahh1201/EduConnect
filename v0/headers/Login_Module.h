#pragma once
#include <iostream>
#include <cstdlib>
using namespace std;
class User
{
public:
	User() //Default constructor if nothing is given
	{
		firstName = "N/A";
		lastName = "N/A";
		userName = "N/A";
		securityQ = "N/A";
		securityA = "N/A";
		userType = 0;
	}

	User(string fN, string lN, string uN, string sQ, string sA, int type) // Constructor that names the object appropriately when creating new Users
	{
		firstName = fN;
		lastName = lN;
		userName = uN;
		securityQ = sQ;
		securityA = sA;
		userType = type;
	}

	~User() //Destructor to an object class
	{
	}

	string getFirstName() const
	{
		return firstName;
	}

	string getLastName() const
	{
		return lastName;
	}

	string getUserName() const
	{
		return userName;
	}

	string getSecurityQ() const
	{
		return securityQ;
	}

	string getSecurityA() const
	{
		return securityA;
	}

	int getUserType() const
	{
		return userType;
	}

private:
	string name;
	string firstName;
	string lastName;
	string userName;
	string securityQ;
	string securityA;
	int userType;
};