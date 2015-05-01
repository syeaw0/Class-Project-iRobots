// pamphlet.cpp
// David Stephan

#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include "Pamphlet.h"

// menuOption -----------------------------------------------
struct Pamphlet::menuOption{
	void (Pamphlet::*func)();
	std::string description;
	menuOption( void(Pamphlet::*f)(), std::string s) : func(f), description(s) {};
};


// Pamphlet ------------------------------------------------

Pamphlet::Pamphlet() : signedIn(true) {
	menu.reserve(20);
	initMenu();
}
Pamphlet::~Pamphlet() {

}
void Pamphlet::addOption( fptr func, std::string s){
	menu.push_back(menuOption(func, s));
}
void Pamphlet::insertOption( fptr func, std::string s){
	menu.insert(menu.begin(), menuOption(func,s));
}
void Pamphlet::menuLoop(){
	int input;
	while(signedIn){
		printMenu();
		input = scanInt(menu.size()-1);
		(this->*menu[input].func)();
	}
}
void Pamphlet::initMenu(){
	addOption( &Pamphlet::PrintRobotOptions , 		"Print Robot Options");
	addOption( &Pamphlet::PrintRobotMaintenance , 	"Print Robot Maintenance");
	addOption( &Pamphlet::PrintRobotPolicy ,		"Print Robot Policy");
	addOption( &Pamphlet::PrintTestimonials , 		"Print Testimonials");
	addOption( &Pamphlet::PrintContacts , 			"Print Contacts");
	addOption( &Pamphlet::SignOut , 				"Signout");
}
void Pamphlet::printMenu(){
	printf(" -- iRobots -- \n");
	for(int i=0; i<menu.size(); i++){
		printf("%d. %s\n", i, menu[i].description.c_str());
	}
}

int Pamphlet::scanInt(int size){
	int input;
	bool failScan;
	do{
		fflush(stdin);
		failScan = !(scanf("%d", &input) && input >= 0 && input <= size);
					// must be a number, >= 0, <= maxsize
					//	try again if fail
		if(failScan) printf("Invalid Input\n");
	}
	while( failScan );
	return input;
}

std::string Pamphlet::scanName(){
	std::string inName;
	std::getline(std::cin, inName);

	// trimming here?
	//		char length
	//		# words
	//		special characters

	return inName;
}

void Pamphlet::PrintRobotInfo(){
	printf("--Print Robot Info\n");
}
void Pamphlet::PrintRobotOptions(){
	printf("--Print Robot Options\n");
}
void Pamphlet::PrintRobotMaintenance(){
	printf("--Print Maintenance\n");
}
void Pamphlet::PrintRobotPolicy(){
	printf("--Print Policy\n");
}
void Pamphlet::PrintTestimonials(){
	printf("--Print Testimonials\n");
}
void Pamphlet::PrintContacts(){
	printf("--Print Contacts\n");
}
void Pamphlet::SignOut(){
	printf("--Sign Out\n");
	signedIn = false;
}



// Guest -----------------------------------------




