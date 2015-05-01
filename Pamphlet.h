// Pamphlet.h
// David Stephan

#ifndef PAMPHLET_H_
#define PAMPHLET_H_

//class Pamphlet;
//struct Pamphlet::menuOption;

#include <string>
#include <vector>
//#include "customerlist.h"


class Pamphlet {
public:
	struct menuOption;

	Pamphlet();
	~Pamphlet();

	void menuLoop();
	// the main function

	typedef void (Pamphlet::*fptr)();
	void addOption( fptr function, std::string description);
	void insertOption( fptr function, std::string decription);
	// when using derived member functions use static_cast<Pamphlet::fptr>()
	//		pointed functions must have void return and void params
	// we could just makes insertions simpler, its easy to switch back to private

	// Various Scan Functions
	int scanInt(int);
	std::string scanName();

	// Various Print Functions
	//void printResponse(std::string);

private:
	bool signedIn;
	std::vector<menuOption> menu;

	void initMenu();
	void printMenu();

	void PrintRobotInfo();
	void PrintRobotOptions();
	void PrintRobotMaintenance();
	void PrintRobotPolicy();
	void PrintTestimonials();
	void PrintContacts();
	void SignOut();
};




#endif /* PAMPHLET_H_ */
