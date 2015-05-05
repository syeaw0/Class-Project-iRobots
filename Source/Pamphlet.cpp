// pamphlet.cpp
// David Stephan


#include "Pamphlet.h"

// Pamphlet ------------------------------------------------

Pamphlet::Pamphlet() : signedIn(true) {
	menu = Menu<fptr>("iRobotsTheBomb Pamphlet");
	initMenu();
}
Pamphlet::~Pamphlet() {

}
void Pamphlet::menuLoop(){
	fptr menuCall;
	while(signedIn){
		menu.print();
		menuCall = menu.eval();
		(this->*menuCall)();

		system("pause");
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
	printf("--base pamphlet help\n");
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




