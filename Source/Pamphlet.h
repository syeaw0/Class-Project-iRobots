// Pamphlet.h
// David Stephan

#ifndef PAMPHLET_H_
#define PAMPHLET_H_

//class Pamphlet;
//struct Pamphlet::menuOption;

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>
#include "Menu.h"
//#include "customerlist.h"

class Pamphlet {
public:
	typedef void (Pamphlet::*fptr)();

	Pamphlet();
	~Pamphlet();

	void menuLoop();
	// the main function

	//void addOption( fptr function, std::string description);
	//void insertOption( fptr function, std::string decription);
	// when using derived member functions use static_cast<Pamphlet::fptr>()
	//		pointed functions must have void return and void params
	// we could just makes insertions simpler, its easy to switch back to private

protected:
	Menu<fptr> menu;

private:
	bool signedIn;

	void initMenu();

	void Help();
	void PrintRobotInfo();
	void PrintRobotOptions();
	void PrintRobotMaintenance();
	void PrintRobotPolicy();
	void PrintTestimonials();
	void PrintContacts();
	void SignOut();
};




#endif /* PAMPHLET_H_ */
