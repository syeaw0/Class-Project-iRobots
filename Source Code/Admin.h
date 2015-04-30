/**********************************************
 * AUTHOR		: David Stephan
 * PROJECT #2	: iRobots
 * CLASS		: CS1C
 * DUE DATE		: 5/15/15
 **********************************************/

#ifndef ADMIN_H_
#define ADMIN_H_

// PRE-PROCESSOR DIRECTIVES

#include "Pamphlet.h"
using namespace std;

/***********************************************
 * CLASS Admin
 * ---------------------------------------------
 * This class represents the pamphlet menu and
 * options for an administrator
 ***********************************************/
class Admin : public Pamphlet {
public:
	Admin();
		//addOption(function1, std::string("Function 1"));

private:
	//CustomerList customers;
	void initMenu();

	void Help();
	void ChangeCustomerInfo();
	void CustomerSearch();
	void AddCustomer();
	void DeleteCustomer();
	void SaveChanges();
	void PrintCustomers();
	void PrintCustomersByName();
};

#endif /* ADMIN_H_ */
