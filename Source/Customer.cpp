// Customer.cpp

#include "Customer.h"
#include <stdio.h>


// Customer -----------------------------------------

Customer::Customer() {
	initMenu();
}
void Customer::initMenu(){
	// note this is reverse order
	menu.insert(static_cast<Pamphlet::fptr>( &Customer::BuyRobot ),	"Buy Robot");
	menu.insert(static_cast<Pamphlet::fptr>( &Customer::Help ), 	"Help");
}
void Customer::Help(){

	Menu<std::string> helpMenu("Customer Help Menu");
	std::string helpText;

	helpMenu.add("Exiting",
			"Exit Help Menu");
	helpMenu.add("To order a pamphlet, select the \"Order Pamphlet\" option from the main menu",
			"Help ordering a pamphlet.");
	helpMenu.add("To order a robot, select \"Order Robot\" from the main menu.",
			"Help ordering a robot.");
	helpMenu.add("To read testimonials, select \"Read Testimonials\" from the main menu.",
			"Help reading testimonials.");
	helpMenu.add("To submit your own testimonials, you must first order a robot. Then select \"Submit Testimonial\" from the main menu.",
			"Help submitting testimonials.");
	helpMenu.add("You may contact us by calling 1 800 555 5555",
			"Contact us.");
	helpMenu.print();

	while(helpText != "Exiting"){
		helpText = helpMenu.eval();
		std::cout << helpText << std::endl;
	}
}
void Customer::BuyRobot(){
	printf("--Buy Robot\n");
}
