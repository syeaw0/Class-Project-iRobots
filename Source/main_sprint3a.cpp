
#define MAIN_SPRINT3
#ifdef MAIN_SPRINT3

//#define NO_LOGIN GUEST	// build with ADMIN, CUSTOMER, or GUEST to bypass login
//#define DEBUG_MENU_TRACE	//


#include "header.h"
#include <stdlib.h>

int main(){

	// VARIABLE DECLARATIONS
	bool        invalid;
	User  		userType;		// The type of user (Admin, Customer, or Guest)
	Login 	  	login;			// The login class object
	Pamphlet*	pamphlet;		// Pointer to the base Pamphlet class

	do{	// eventually replace loop

		// VARIABLE INITIALIZATION
		login.InitializeInfo("LoginInfoTest.txt");
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
			catch(Login::Exit&){
				return 0;
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
		login.ResetInfo();

	} while (1);
}

#endif
