// pamphlet.cpp
// David Stephan

#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include "pamphlet.h"

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


// Admin -----------------------------------------

PAdmin::PAdmin() {
	initMenu();
}

void PAdmin::initMenu(){

	// Additions, the menu ends up in an ugly order
	//addOption(static_cast<Pamphlet::fptr>( &PAdmin::Help ), 					"Help");
	//addOption(static_cast<Pamphlet::fptr>( &PAdmin::ChangeCustomerInfo ), 	"Change Customer Info");
	//addOption(static_cast<Pamphlet::fptr>( &PAdmin::CustomerSearch ), 		"Customer Search");
	//addOption(static_cast<Pamphlet::fptr>( &PAdmin::AddCustomer ), 			"Add Customer");
	//addOption(static_cast<Pamphlet::fptr>( &PAdmin::DeleteCustomer ), 		"Delete Customer");
	//addOption(static_cast<Pamphlet::fptr>( &PAdmin::SaveChanges ), 			"Save Changes");
	//addOption(static_cast<Pamphlet::fptr>( &PAdmin::PrintCustomers ), 		"Print Customers");
	//addOption(static_cast<Pamphlet::fptr>( &PAdmin::PrintCustomersByName ), 	"Print Customers By Name");

	// Insertions instead
	insertOption(static_cast<Pamphlet::fptr>( &PAdmin::PrintCustomersByName ),  "Print Customers By Name");
	insertOption(static_cast<Pamphlet::fptr>( &PAdmin::PrintCustomers ), 		"Print Customers");
	insertOption(static_cast<Pamphlet::fptr>( &PAdmin::SaveChanges ), 			"Save Changes");
	insertOption(static_cast<Pamphlet::fptr>( &PAdmin::DeleteCustomer ), 		"Delete Customer");
	insertOption(static_cast<Pamphlet::fptr>( &PAdmin::AddCustomer ), 			"Add Customer");
	insertOption(static_cast<Pamphlet::fptr>( &PAdmin::CustomerSearch ), 		"Customer Search");
	insertOption(static_cast<Pamphlet::fptr>( &PAdmin::ChangeCustomerInfo ), 	"Change Customer Info");
	insertOption(static_cast<Pamphlet::fptr>( &PAdmin::Help ), 					"Help");

	// Alternatively w/ public menu
	//		menu.insert(menu.begin(), menuOption(static_cast<Pamphlet::fptr>( &PAdmin::Help ), "Help"));
	//			OR
	//		menu.push_back(menuOption(static_cast<Pamphlet::fptr>( &PAdmin::Help ), 			"Help");
}

void PAdmin::Help(){
	printf("--Help You!\n");
}
void PAdmin::ChangeCustomerInfo(){
	printf("--Change Customer Info\n");
}
void PAdmin::CustomerSearch(){
	printf("--Customer Search\n");
}
void PAdmin::AddCustomer(){
	printf("--Add Customer\n");

	// cin customers?
}
void PAdmin::DeleteCustomer(){
	printf("--Delete\n");


}
void PAdmin::SaveChanges(){
	printf("--Saving\n");

	// customer.save
}
void PAdmin::PrintCustomers(){
	printf("--Printing\n");

	// customers.printAll()
}
void PAdmin::PrintCustomersByName(){
	printf("--PrintByName\n");
	std::string inName = scanName();

	// customers.lookup(inName);
}

// Customer -----------------------------------------

PCustomer::PCustomer() {
	initMenu();
}
void PCustomer::initMenu(){
	// note this is reverse order
	insertOption(static_cast<Pamphlet::fptr>( &PCustomer::BuyRobot ),	"Buy Robot");
	insertOption(static_cast<Pamphlet::fptr>( &PCustomer::Help ), 		"Help");
}
void PCustomer::Help(){
	printf("--Help You!\n");
}
void PCustomer::BuyRobot(){
	printf("--Buy Robot\n");
}

// Guest -----------------------------------------

PGuest::PGuest() {
	initMenu();
}
void PGuest::initMenu(){
	insertOption(static_cast<Pamphlet::fptr>( &PGuest::RequestPamphlet ),	"Request Pamphlet");
	insertOption(static_cast<Pamphlet::fptr>( &PGuest::Help ), 				"Help");
}
void PGuest::Help(){
	printf("--Help You!\n");
}
void PGuest::RequestPamphlet(){
	printf("--Buy Robot\n");
}





