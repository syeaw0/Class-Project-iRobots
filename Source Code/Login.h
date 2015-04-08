/**********************************************
 * AUTHOR		: Samuel Yeaw
 * STUDENT ID	: 726729
 * PROJECT #2	: iRobot
 * CLASS		: CS1C
 * DUE DATE		: 5/12/2015
 **********************************************/

#ifndef LOGIN_H_
#define LOGIN_H_

// PRE-PROCESSOR DIRECTIVES

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

// USER DEFINED TYPES

enum	User
{
	ADMIN,
	CUSTOMER,
	GUEST
};

struct 	LoginInfo
{
	string username;
	string password;
};

/**********************************************
 * CLASS Login
 * --------------------------------------------
 * This class handles the login feature of the
 * program. It takes a username and password
 * and logs the user in to the correct
 * pamphlet
 **********************************************/
class Login
{
private:
	/*ATTRIBUTES*/
	LoginInfo loginInfo;		// The user's username and password
	LoginInfo adminInfo;		// The admin's username and password. The
								// loginInfo attribute takes input from
								// the user and compares it to adminInfo
								// to see if the user is an admin
	vector<LoginInfo> customerInfo;	// A vector containing the usernames
									// and passwords of all customers

	// EXCEPTION CLASSES
	class CorruptFile{};

public:
	/*METHODS*/
	Login();		// Default Constructor
	~Login();		// Destructor

	// MUTATORS
	void InitializeInfo(ifstream& inFile);	// Reads in the usernames and
											// passwords from a file
	void NewAccount();						// Creates a new account
											// and saves it to a file

	// ACCESSORS
	User UserLogin();						// Logs the user in as a
											// guest, customer, or admin
};

#endif /* LOGIN_H_ */
