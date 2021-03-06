// Admin.h

#ifndef ADMIN_H_
#define ADMIN_H_

#include "Pamphlet.h"
#include "CustomerListType.h"
//#include "Customer.h"
#include "Login.h"
#include "input.h"
#include <stdio.h>

class Admin : public Pamphlet {
public:
	Admin();
	virtual ~Admin();
		//addOption(function1, std::string("Function 1"));

private:
	CustomerListType customers;

	void initMenu();

	void Help();
	void ChangeCustomerInfo();
	void CustomerSearch();
	void AddCustomer();
	void DeleteCustomer();
	void AddGuestToBeACustomer();
	void SaveChanges();
	void PrintCustomers();
	void PrintKeyCustomers();
	void AddAccount();
	void DeleteAccount();
};




#endif /* ADMIN_H_ */
