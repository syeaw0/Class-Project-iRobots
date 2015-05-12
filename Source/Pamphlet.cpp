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
	menu.add( &Pamphlet::PrintRobotOptions , 	"Print Robot Options");
	menu.add( &Pamphlet::PrintRobotMaintenance ,"Print Robot Maintenance");
	menu.add( &Pamphlet::PrintRobotPolicy ,		"Print Robot Policy");
	menu.add( &Pamphlet::PrintTestimonials , 	"Print Testimonials");
	menu.add( &Pamphlet::PrintContacts , 		"Print Contacts");
	menu.add( &Pamphlet::SignOut , 				"Signout");
}

void Pamphlet::Help(){
	printf("--base pamphlet help (I dont think this is ever used)\n");
}
void Pamphlet::PrintRobotInfo(){
	printf("--Print Robot Info\n");
	std::cout << robotInfo.GetOptions() << std::endl;
}
void Pamphlet::PrintRobotOptions(){
	printf("--Print Robot Options\n");
	std::cout << robotInfo.GetOptions() << std::endl;
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
	//
}
void Pamphlet::SignOut(){
	printf("--Sign Out\n");
	signedIn = false;
}


// Guest -----------------------------------------




