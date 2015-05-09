
#define MAIN_SPRINT3
#ifdef MAIN_SPRINT3

//#define DEBUG_MENU_TRACE	//
//#define NO_LOGIN GUEST	// build with ADMIN, CUSTOMER, or GUEST to bypass login

#include "header.h"

int main(){

	// VARIABLE DECLARATIONS
	bool        invalid;
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
		do
		{
			invalid = false;

			try
			{
				userType = login.UserLogin();
			}

			catch(Login::InvalidPassword&)
			{
				cout << "*** Invalid Password ***\n";
				invalid = true;
			}
			catch(Login::InvalidUsername&)
			{
				cout << "*** Invalid Username ***\n";
				invalid = true;
			}
		}while(invalid);
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
