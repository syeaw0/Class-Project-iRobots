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
#include <sstream>
#include "Menu.h"
#include "Robot.h"
#include "Testimonials.h"
//#include "customerlist.h"

// PROTOTYPE FOR WORD WRAP

/**************************************************
 * WordWrap
 * ------------------------------------------------
 * This function wraps the text around a specified
 * limit
 **************************************************/
void WordWrap(string  text, 	// IN   - The text to word wrap
			  int     maxLen,	// CALC - The maximum characters in a line
			  ostream &oFile);	// OUT 	- The file to output to

class Pamphlet {
public:
	typedef void (Pamphlet::*fptr)();

	Pamphlet();
	virtual ~Pamphlet();

	bool GetSignedIn();
	virtual void menuLoop();
	// the main function

	//void addOption( fptr function, std::string description);
	//void insertOption( fptr function, std::string decription);
	// when using derived member functions use static_cast<Pamphlet::fptr>()
	//		pointed functions must have void return and void params
	// we could just makes insertions simpler, its easy to switch back to private

protected:
	Menu<fptr> menu;

private:
	Robot robotInfo; // this might have to be protected for "customer" use
	bool signedIn;
	Testimonials testInfo;

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
