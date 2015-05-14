// pamphlet.cpp
// David Stephan


#include "Pamphlet.h"

// Pamphlet ------------------------------------------------

Pamphlet::Pamphlet() : signedIn(true) {
	menu = Menu<fptr>("iRobotsTheBomb Pamphlet");
	initMenu();
	robotInfo.Initialize("RobotInfo.txt");
	testInfo.AddFromFile("TestimonialsInfo.txt");
}
Pamphlet::~Pamphlet() {

}
void Pamphlet::menuLoop(){
	fptr menuCall;
	while(signedIn){
		menu.print();
		menuCall = menu.eval();
		(this->*menuCall)();
	}
}
void Pamphlet::initMenu(){
	menu.add( &Pamphlet::PrintRobotSalesPitch , "Why Should I Buy This?");
	menu.add( &Pamphlet::PrintRobotEnvironment, "Print Robot Physical Environment");
	menu.add( &Pamphlet::PrintRobotOperations , "Print Robot Concept of Operations");
	menu.add( &Pamphlet::PrintRobotMaintenance ,"Print Robot Maintenance");
	menu.add( &Pamphlet::PrintRobotPolicy ,		"Print Robot Policy");
	menu.add( &Pamphlet::PrintTestimonials , 	"Print Testimonials");
	menu.add( &Pamphlet::PrintContacts , 		"Print Contacts");
	menu.add( &Pamphlet::SignOut , 				"Signout");
}

bool Pamphlet::GetSignedIn()
{
	return signedIn;
}

void Pamphlet::Help(){
	Menu<std::string> helpMenu("iRobotsTheBomb Menu");
	std::string helpText;

	helpMenu.add("Exiting",
			"Exit Help Menu");
	helpMenu.add("To view robots, select \"Print Robot Options\" from the main menu.",
			"Help viewing robot options.");
	helpMenu.add("To view robot maintenance plans, select \"Print Robot Maintenance\" from the main menu.",
			"Help viewing robot maintenance options.");
	helpMenu.add("To view robot guarantee policy, select \"Print Robot Policy\" option from the main menu",
			"Help viewing robot guarantee policy.");
	helpMenu.add("To read testimonials, select \"Read Testimonials\" from the main menu.",
			"Help reading testimonials.");
	helpMenu.add("You may contact us by calling 1 800 555 5555",
			"Contact us.");
	helpMenu.print();

	while(helpText != "Exiting"){
		helpText = helpMenu.eval();
		std::cout << helpText << std::endl;
	}
}
void Pamphlet::PrintRobotSalesPitch(){
	printf("--Print Robot Sales Pitch\n");
	std::cout << robotInfo.GetSalesPitch() << std::endl;
}
void Pamphlet::PrintRobotEnvironment(){
	printf("--Print Robot Environment\n");
	std::cout << robotInfo.GetEnvironment() << std::endl;
}
void Pamphlet::PrintRobotOperations(){
	printf("--Print Robot Operations\n");
	std::cout << robotInfo.GetOperations() << std::endl;
}
void Pamphlet::PrintRobotMaintenance(){
	printf("--Print Maintenance\n");
	std::cout << robotInfo.GetMaintenance() << std::endl;
}
void Pamphlet::PrintRobotPolicy(){
	printf("--Print Policy\n");
	std::cout << robotInfo.GetPolicy() << std::endl;
}
void Pamphlet::PrintTestimonials(){
	printf("--Print Testimonials\n");
	testInfo.ClearTestimonials();
	testInfo.AddFromFile("TestimonialsInfo.txt");
	testInfo.Print();
}
void Pamphlet::PrintContacts(){
	printf("--Print Contacts\n");
	printf("\niRobotsTheBomb\n"
			"12 Bomb Lane\n"
			"Mission Viejo, CA 92692");
	printf("T: 1-800-555-5555\n");
	//
}
void Pamphlet::SignOut(){
	printf("--Sign Out\n");
	signedIn = false;
}


// Guest -----------------------------------------




