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
	menu.add( &Pamphlet::PrintRobotInfo,        "Print Robot Info");
	menu.add( &Pamphlet::PrintRobotOptions , 	"Print Robot Options");
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
void Pamphlet::PrintRobotInfo(){
	printf("--Print Robot Info\n");
	WordWrap(robotInfo.GetSalesPitch(), 75, cout);
	WordWrap(robotInfo.GetEnvironment(), 75, cout);
	WordWrap(robotInfo.GetOperations(), 75, cout);
}
void Pamphlet::PrintRobotOptions(){
	printf("--Print Robot Options\n");
	WordWrap(robotInfo.GetOptions(), 75, cout);
}
void Pamphlet::PrintRobotMaintenance(){
	printf("--Print Maintenance\n");
	WordWrap(robotInfo.GetMaintenance(), 75, cout);
}
void Pamphlet::PrintRobotPolicy(){
	printf("--Print Policy\n");
	WordWrap(robotInfo.GetPolicy(), 75, cout);
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
	cout << endl << endl;
	//
}
void Pamphlet::SignOut(){
	printf("--Sign Out\n");
	signedIn = false;
}

/**************************************************
 * WordWrap
 * ------------------------------------------------
 * This function wraps the text around a specified
 * limit
 * ------------------------------------------------
 * PRE-CONDITIONS
 * 	text	: The text to word wrap
 * 	maxLen	: The maximum character limit in a line
 * 	oFile	: The output file
 *
 * POST-CONDITIONS
 * 	<Outputs the modified text>
 **************************************************/

void WordWrap(string  text, 	// IN   - The text to word wrap
			  int     maxLen,	// CALC - The maximum characters in a line
			  ostream &oFile)	// OUT 	- The file to output to
{
	string word;
	string line;
	int    textLen;
	int    count;

	textLen = text.length();

	for(count = 0; count <= textLen + 1; count++)
	{
		if(!isspace(text[count]) && count < textLen)
		{
			word += text[count];
		}
		else
		{
			if(line.length() + word.length() > (unsigned int)maxLen
			   || count == textLen + 1)
			{
				oFile << line << endl;
				line.clear();
			}

			line += word + ' ';
			word.clear();
		}
	}

	cout << endl << endl;
}



// Guest -----------------------------------------




