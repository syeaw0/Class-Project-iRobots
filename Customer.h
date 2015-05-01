/*
 * Customer.h
 *
 *  Created on: Apr 30, 2015
 *      Author: dstephan1
 */

#ifndef CUSTOMER_H_
#define CUSTOMER_H_

#include "Pamphlet.h"


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
