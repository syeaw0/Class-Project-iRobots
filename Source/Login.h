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
#include <limits>
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

	/*PRIVATE METHODS*/
	// MUTATORS
	void Save(string outputFile);	// Saves the login information by
									// writing it to the input file
public:
	/*METHODS*/
	Login();		// Default Constructor
	~Login();		// Destructor

	// MUTATORS
	void InitializeInfo(string inputFile);	// Reads in the usernames and
											// passwords from a file
	void ResetInfo();						// Resets login
	void NewAccount(string outputFile);		// Creates a new account
											// and saves it to a file
	void DeleteAccount(string outputFile);	// Deletes a user account

	// ACCESSORS
	User UserLogin()const;					// Logs the user in as a
											// guest, customer, or admin


	// EXCEPTION CLASSES
	class CorruptFile{};		// An exception for if the file is not found
	class InvalidPassword{};	// For when the user's password does not
								// match their username
	class InvalidUsername{};	// For when the entered username is not found
	class UsernameTaken{};		// For if a username has been taken when
								// creating a new account
	class Exit{};
};

#endif /* LOGIN_H_ */
