/**********************************************
 * AUTHOR		: David Stephan
 * PROJECT #2	: iRobots
 * CLASS		: CS1C
 * DUE DATE		: 5/15/15
 **********************************************/

#include "Customer.h"

Customer::Customer() {
	initMenu();
}
void Customer::initMenu(){
	// note this is reverse order
	insertOption(static_cast<Pamphlet::fptr>( &Customer::BuyRobot ),	"Buy Robot");
	insertOption(static_cast<Pamphlet::fptr>( &Customer::Help ), 		"Help");
}
void Customer::Help(){
	printf("--Help You!\n");
}
void Customer::BuyRobot(){
	printf("--Buy Robot\n");
}


