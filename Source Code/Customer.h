/**********************************************
 * AUTHOR		: David Stephan
 * PROJECT #2	: iRobots
 * CLASS		: CS1C
 * DUE DATE		: 5/15/15
 **********************************************/

#ifndef CUSTOMER_H_
#define CUSTOMER_H_

// PRE-PROCESSOR DIRECTIVES

#include "Pamphlet.h"
using namespace std;

/**********************************************
 * CLASS Customer
 * --------------------------------------------
 * This class represents the pamphlet menu
 * and options for a customer
 **********************************************/
class Customer : public Pamphlet {
public:
	Customer();
		//addOption(function1, std::string("Function 1"));
private:
	//CustomerList customers;
	void initMenu();

	void Help();
	void BuyRobot();
};

#endif /* CUSTOMER_H_ */
