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

// Saves the login information by writing it to the input file
void Login::Save(string outputFile)
{
	// VARIABLE DECLARATIONS
	int 		index;
	int 		size;
	ofstream	oFile;

	// VARIABLE INITIALIZATION
	index = 0;
	size  = signed(customerInfo.size());
	oFile.open(outputFile.c_str());

	// OUTPUT THE ADMIN USERNAME AND PASSWORD TO THE FILE
	oFile << adminInfo.username << endl;
	oFile << adminInfo.password;

	// OUTPUT THE CUSTOMER USERNAMES AND PASSWORDS TO THE FILE
	while(index < size)
	{
		oFile << endl;
		oFile << customerInfo[index].username << endl;
		oFile << customerInfo[index].password;

		index++;
	}

	oFile.close();
}

// Reads in the passwords and usernames from a file
// Throws CorruptFile exception if no file is found
void Login::InitializeInfo(string inputFile)
{
	// VARIABLE DECLARATIONS
	ifstream  inFile;
	LoginInfo login;

	// OPEN INPUT FILE
	inFile.open(inputFile.c_str());

	// TEST IF FILE IS FOUND
	if(inFile.eof())
	{
		throw CorruptFile();
	}
	else
	{
		// READ IN ADMIN USERNAME AND PASSWORD
		getline(inFile, adminInfo.username);
		getline(inFile, adminInfo.password);

		// READ IN CUSTOMERS USERNAME AND INFO
		while(!inFile.eof())
		{
			getline(inFile, login.username);
			getline(inFile, login.password);

			customerInfo.push_back(login);
		}
	}

	// CLOSE FILE
	inFile.close();
}

// Creates a new account for a new user.
// Throws a UsernameTaken exception
void Login::NewAccount(string outputFile)
{
	// VARIABLE DECLARATIONS
	int			index;
	int			size;
	LoginInfo 	login;

	// VARIABLE INITIALIZATION
	index 			= 0;
	size			= signed(customerInfo.size());

	cout << "Please enter a username: ";
	getline(cin, login.username);

	// CHECK IF ADMIN USERNAME IS TAKEN
	if(login.username == adminInfo.username)
	{
		throw UsernameTaken();
	}

	// CHECK IF CUSTOMER USERNAMES ARE TAKEN
	while(index < size)
	{
		cout << customerInfo[index].username << "==" << login.username << endl;

		if(customerInfo[index].username == login.username)
		{
			throw UsernameTaken();
		}
		else
		{
			index++;
		}
	}

	cout << "\n Your new username is " << login.username << "!\n\n";

	cout << "Please enter a password: ";
	getline(cin, login.password);
	cout << "\n Your new password is " << login.password << "!\n\n";

	customerInfo.push_back(login);

	Save(outputFile);
}

// Logs the user in as an ADMIN, CUSTOMER, or GUEST.
// Throws InvalidUsername and InvalidPassword exceptions
User Login::UserLogin()const
{
	// VARIABLE DECLARATIONS
	int			index;
	int			size;
	bool		found;
	User 		user;
	LoginInfo 	login;

	// DISPLAY INSTRUCTIONS
	cout << "********************************************************\n"
			"* Please enter your username and password. If you are  *\n"
			"* a guest, simply type 'guest' as your username.       *\n"
			"* The username and password are case sensitive.        *\n"
			"********************************************************\n\n";

	// PROMPT THE USER FOR THEIR USERNAME
	cout << "Username: ";
	getline(cin, login.username);

	// - IF USERNAME IS GUEST, RETURN 'GUEST'
	// - ELSE IF USERNAME IS NOT AN ADMIN, CHECK CUSTOMERS' USERNAMES
	// - ELSE PROMPT USER FOR ADMIN PASSWORD
	if(login.username == "guest")
	{
		user = GUEST;
	}
	else if(login.username != adminInfo.username)
	{
		// LOOP - SEARCH THROUGH CUSTOMER USERNAMES FOR MATCH
		index = 0;
		size  = signed(customerInfo.size());
		found = false;
		while(index < size && !found)
		{
			// - IF USERNAME MATCHES A CUSTOMER USERNAME, CHECK THE PASSWORD
			// - ELSE GO TO THE NEXT CUSTOMER
			if(login.username == customerInfo[index].username)
			{
				// PROMPT USER FOR PASSWORD
				cout << "Password: ";
				getline(cin, login.password);

				// - IF PASSWORD MATCHES THE CUSTOMER'S PASSWORD, RETURN 'CUSTOMER'
				// - ELSE THROW 'InvalidPassword' EXCEPTION
				if(login.password == customerInfo[index].password)
				{
					user  = CUSTOMER;
					found = true;
				}
				else
				{
					throw InvalidPassword();
				}
			}
			else
			{
				index++;
			}
		}

		// IF THE USERNAME HAS NO ADMIN OR CUSTOMER MATCHES, THROW
		// AN 'InvalidUsername' EXCEPTION
		if(!found)
		{
			throw InvalidUsername();
		}
	}
	else
	{
		// PROMPT USER FOR PASSWORD
		cout << "Password: ";
		getline(cin, login.password);

		// - IF PASSWORD MATCHES THE ADMIN PASSWORD, RETURN 'ADMIN'
		// - ELSE THROW 'InvalidPassword' EXCEPTION
		if(login.password == adminInfo.password)
		{
			user = ADMIN;
		}
		else
		{
			throw InvalidPassword();
		}
	}

	cout << endl;

	return user;
}
