// Guest.h

#ifndef GUEST_H_
#define GUEST_H_

#include "Pamphlet.h"
#include "CustomerListType.h"
#include "Login.h"
#include <stdio.h>

class Guest : public Pamphlet {
public:
	Guest();
	virtual ~Guest();
		//addOption(function1, std::string("Function 1"));

private:
	//CustomerList customers;
	void initMenu();

	void Help();
	void RequestPamphlet();
};

#endif /* GUEST_H_ */
