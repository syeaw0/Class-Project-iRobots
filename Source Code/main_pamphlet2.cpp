
#include "pamphlet.h"

int main(){

	// Testing each one
	Pamphlet* pamphlet = new PAdmin();
	pamphlet->menuLoop();
	delete pamphlet;


	pamphlet = new PGuest();
	pamphlet->menuLoop();
	delete pamphlet;

	pamphlet = new PCustomer();
	pamphlet->menuLoop();
	delete pamphlet;

	return 0;
}

