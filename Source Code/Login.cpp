/**********************************************
 * AUTHOR		: Samuel Yeaw
 * STUDENT ID	: 726729
 * PROJECT #2	: iRobot
 * CLASS		: CS1C
 * DUE DATE		: 5/12/2015
 **********************************************/

#include "Login.h"

// Default Constructor
Login::Login()
{

}

// Destructor
Login::~Login()
{

}

// Reads in the passwords and usernames from a file
// Throws CorruptFile exception if no file is found
void Login::InitializeInfo(ifstream& inFile)
{
	// VARIABLE DECLARATIONS
	int index;

	// TEST IF FILE IS FOUND
	if(!inFile)
	{
		throw CorruptFile();
	}
	else
	{
		// READ IN ADMIN USERNAME AND PASSWORD
		getline(inFile, adminInfo.username);
		getline(inFile, adminInfo.password);

		// READ IN CUSTOMERS USERNAME AND INFO
		index = 0;
		while(inFile)
		{
			getline(inFile, customerInfo[index].username);
			getline(inFile, customerInfo[index].password);
			index++;
		}
	}
}

void Login::NewAccount()
{

}

User Login::UserLogin()
{
	// VARIABLE DECLARATIONS
	User 		user;
	LoginInfo 	login;

	// WELCOME TEXT
	cout << "Welcome to the iRobot Online Pamphlet!\n";
	cout << "Please login to continue\n";

	// PROMPT THE USER FOR THEIR USERNAME AND PASSWORD
	cout << "Username: ";
	getline(cin, login.username);

	// TODO - TEST FOR INVALID INPUT/ USERNAME/ PASSWORD

	cout << "Password: ";
	getline(cin, login.password);
}
