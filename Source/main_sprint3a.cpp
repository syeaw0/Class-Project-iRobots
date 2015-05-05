
#define MAIN_SPRINT3
#ifdef MAIN_SPRINT3

//#define DEBUG_MENU_TRACE	//
//#define NO_LOGIN CUSTOMER	// build with ADMIN, CUSTOMER, or GUEST to bypass login

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <limits>

#include "CustomerListType.h"
#include "Pamphlet.h"
#include "Admin.h"
#include "Customer.h"
#include "Guest.h"
#include "Login.h"

int main(){

	// VARIABLE DECLARATIONS
	User  		userType;		// The type of user (Admin, Customer, or Guest)
	Login 	  	login;			// The login class object
	Pamphlet*	pamphlet;		// Pointer to the base Pamphlet class



	// VARIABLE INITIALIZATION
	login.InitializeInfo("LoginInfoTest.txt");


	while(1){	// eventually replace loop
		#ifdef NO_LOGIN
		userType = NO_LOGIN;
		#else
		// USER LOGIN
		userType = login.UserLogin();
		#endif
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

		pamphlet->menuLoop();

	}
}

#endif
