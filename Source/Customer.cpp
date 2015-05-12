// Customer.cpp

#include "Customer.h"
#include <stdio.h>


// Customer -----------------------------------------

Customer::Customer() {
	initMenu();
}

Customer::~Customer(){

}

void Customer::menuLoop(){
	fptr menuCall;
	while(GetSignedIn()){
		menu.print();
		menuCall = menu.eval();
		(this->*menuCall)();
		aTest.SolicitForTestimonial();
	}
}

void Customer::initMenu(){
	// note this is reverse order
	menu.insert(static_cast<Pamphlet::fptr>( &Customer::AddTestimonial ), 	"Add A Testimonial");
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
	int numToBuy;         //the number of robots to be purchased
	ostringstream prompt; //contains the number of robots to buy prompt
	string address;
	string robot;

	printf("--Buy Robot\n");

	//initializes robotMenu with menu title and options.
	Menu<std::string> robotMenu("Please select the robot you would like to "
			                    "purchase.");
	robotMenu.add("Exiting", "Exit Purchase Menu");
	robotMenu.add("Standard", "Standard");
	robotMenu.add("Rock Climber", "Rock Climber");
	robotMenu.add("Dance Dance Bomb Diffusion", "Dance Dance Bomb Diffusion");

	//prints the Buy Robot menu and gets input
	robotMenu.print();

	if(address == "Exiting"){
		address = robotMenu.eval();
		std::cout << address << std::endl;
	}

	//assigns the prompt for number of robots to buy
	prompt << "\nHow many " <<  robotMenu.eval() << "robots would you like to "
			  "buy? ";

	//Prompts and reads in the number of the selected robot to be purchased
	numToBuy = input::scanIntPrompt(prompt.str(), "***Invalid Quantity***", 1, 1000);
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	//outputs the appropriate congratulatory  message
	if(numToBuy == 1)
	{
		std::cout << "\nCongratulations on your new " << address
				  << " robot!\nYour robot will arrive shortly.\n\n";
	}
	else
	{
		std::cout << "\nCongratulations on your " << numToBuy << " new "
				  << address << " robots!\nYour robots will arrive "
						                 "shortly.\n\n";
	}

}

void Customer::AddTestimonial(){
	printf("--Add a Testimonial\n");
	aTest.AddTestimonial("TestimonialsInfo.txt");
}
