
#define MAIN_SPRINT2
#ifdef MAIN_SPRINT2

#include <stdio.h>
#include <iostream>

#include "CustomerListType.h"
#include "Pamphlet.h"
#include "Admin.h"
#include "Customer.h"
#include "Guest.h"


int main(){

	Pamphlet* pamphlet = new Admin();
	pamphlet->menuLoop();
	delete pamphlet;

	pamphlet = new Guest();
	pamphlet->menuLoop();
	delete pamphlet;

	pamphlet = new Customer();
	pamphlet->menuLoop();
	delete pamphlet;
}

#endif
