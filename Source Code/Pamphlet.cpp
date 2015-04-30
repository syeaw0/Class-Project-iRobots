#include "header.h"
//constructor
Pamphlet::Pamphlet()
{}
//destructor
Pamphlet::~Pamphlet()
{}
//accesses the help menu
void Pamphlet::Help()
{
	int option;
	HelpMenu help;
	ostringstream output;

	output << setw(41) << setfill('*') << '*' << endl;
	output << '?' << setw(40) << setfill(' ') << '?' << endl;
	output << left << setw(40) << "?  1) Help ordering a pamphlet." << "?\n";
	output << setw(40) << '?' << '?' << endl;
	output << left << setw(40) << "?  2) Help ordering a robot." << "?\n";
	output << setw(40) << '?' << '?' << endl;
	output << left << setw(40) << "?  3) Help reading testimonials." << "?\n";
	output << setw(40) << '?' << '?' << endl;
	output << left << setw(40) << "?  4) Help submitting testimonials." << "?\n";
	output << setw(40) << '?' << '?' << endl;
	output << left << setw(40) << "?  5) Contact us." << "?\n";
	output << setw(40) << '?' << '?' << endl;
	output << left << setw(40) << "?  0) Exit Help Menu" << "?\n";
	output << setw(40) << '?' << '?' << endl;
	output << setw(41) << setfill('*') << '*' << endl;
	output << "\nPlease select a help option: ";

	option = GetAndCheckInput(output.str(),0,5);

	switch (option)
	{
	case 0 : help = EXIT;
		break;
	case 1 : help = ORDER_PAMPHLET;
		break;
	case 2 : help = ORDER_ROBOT;
		break;
	case 3 : help = READ_TESTIMONIALS;
		break;
	case 4 : help = SUBMIT_TESTIMONIAL;
		break;
	case 5 : help = CONTACT_US;
		break;
	}

	switch (help)
	{
	case ORDER_PAMPHLET : cout << "\nTo order a pamphlet, select the"
			                      " \"Order Pamphlet\" option from the main menu";
		break;
	case ORDER_ROBOT :  cout << "\nTo order a robot, select \"Order Robot\" from"
			                    " the main menu.";
		break;
	case READ_TESTIMONIALS :  cout << "\nTo read testimonials, select\"Read "
			                          "testimonials\" from the main menu.";
		break;
	case SUBMIT_TESTIMONIAL :  cout << "\nTo submit your own testimonial, you must"
			                           " first order a robot.  Then select \"Submit"
									   " Testimonial\" from the main menu.";
		break;
	case CONTACT_US :  cout << "\nYou may contact us by calling 1 800 555 5555";
		break;
	case EXIT :;
		break;
	}
}



