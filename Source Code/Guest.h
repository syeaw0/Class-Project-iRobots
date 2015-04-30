/**********************************************
 * AUTHOR		: David Stephan
 * PROJECT #2	: iRobots
 * CLASS		: CS1C
 * DUE DATE		: 5/15/15
 **********************************************/

#ifndef GUEST_H_
#define GUEST_H_

// PRE-PROCESSOR DIRECTIVES

#include "Pamphlet.h"
using namespace std;

/***********************************************
 * CLASS Guest
 * ---------------------------------------------
 * This class represents the pamphlet menu and
 * options for a guest
 ***********************************************/
class Guest : public Pamphlet {
public:
	Guest();
		//addOption(function1, std::string("Function 1"));

private:
	//CustomerList customers;
	void initMenu();

	void Help();
	void RequestPamphlet();
};

#endif /* GUEST_H_ */
