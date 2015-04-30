/**********************************************
 * AUTHOR		: Samuel Yeaw
 * STUDENT ID	: 726729
 * PROJECT #2	: iRobot
 * CLASS		: CS1C
 * DUE DATE		: 5/12/2015
 **********************************************/

#include "Header.h"

/**********************************************
 * PROGRAM iRobot
 * --------------------------------------------
 * This program is an online pamphlet for the
 * company iRobotTheBomb Inc.
 **********************************************/
int main()
{
	// VARIABLE DECLARATIONS
	User  		userType;		// The type of user (Admin, Customer, or Guest)
	Login 	  	login;			// The login class object
	Pamphlet*	pamphlet;		// Pointer to the base Pamphlet class

	// VARIABLE INITIALIZATION
	login.InitializeInfo("LoginInfoTest.txt");

	// USER LOGIN
	userType = login.UserLogin();

	// OPEN PAMPHLET DEPENDING ON USER TYPE
	switch(userType)
	{
	case ADMIN:		pamphlet = new Admin;
					break;
	case CUSTOMER:	pamphlet = new Customer;
					break;
	case GUEST:		pamphlet = new Guest;
					break;
	default:		break;
	}

	return 0;
}
