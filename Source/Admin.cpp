// Admin.cpp

#include "Admin.h"

Admin::Admin() {
	initMenu();
	customers.AddFromFile("CustomerList.txt");
	//newCustomers.AddFromFile("P
}

Admin::~Admin(){

}

void Admin::initMenu(){
	// Insertions
	menu.insert(static_cast<Pamphlet::fptr>( &Admin::PrintCustomersByName ), 	"Print Customers By Name");
	menu.insert(static_cast<Pamphlet::fptr>( &Admin::PrintCustomers ), 			"Print Customers");
	menu.insert(static_cast<Pamphlet::fptr>( &Admin::PrintKeyCustomers ), 		"Print Key Customers");
	menu.insert(static_cast<Pamphlet::fptr>( &Admin::SaveChanges ), 			"Save Changes");
	menu.insert(static_cast<Pamphlet::fptr>( &Admin::DeleteCustomer ), 			"Delete Customer");
	menu.insert(static_cast<Pamphlet::fptr>( &Admin::AddCustomer ), 			"Add Customer");
	menu.insert(static_cast<Pamphlet::fptr>( &Admin::AddGuestToBeACustomer ), "Add Guest To Become A Customer");
	menu.insert(static_cast<Pamphlet::fptr>( &Admin::CustomerSearch ), 			"Customer Search");
	menu.insert(static_cast<Pamphlet::fptr>( &Admin::ChangeCustomerInfo ), 		"Change Customer Info");
	menu.insert(static_cast<Pamphlet::fptr>( &Admin::Help ), 					"Help");

}

void Admin::Help(){
	Menu<std::string> helpMenu("Admin Help Menu");
	std::string helpText;

	helpMenu.add("Exiting",
			"Exit Help Menu");
	helpMenu.add("To change information about a customer, select \"Change Customer Info\" option from the main menu.\nYou will need to know the name of the customer in order to change information about that customer.\nYou will also be given an option of what information to change.",
			"Help Change Customer Info");
	helpMenu.add("To search for a customer, select \"Customer Search\" from the main menu.",
			"Help Search For a Customer.");
	helpMenu.add("To add guests as customers, select \"Add Guest To Become A Customer\" from the main menu.",
			"Help To Change Guests to Become A Customer.");
	helpMenu.add("To add a customer, select \"Add Customers\", from the main menu.\nYou will need to provide information about the customer.",
			"Help to add a customer.");
	helpMenu.add("To remove a customer from iRobotsTheBomb, select \"Delete Customer\", from the main menu.\nYou will need to provide the name of the customer to delete.",
			"Help to remove a customer");
	helpMenu.add("To save changes made, select \"Save Changes\", from the main menu.",
			"Help To Save Changes");
	helpMenu.add("To print KEY customers only, select \"Print Key Customers\", from the main menu.",
			"Help To Print Only Key Customers");
	helpMenu.add("To Print all customers, select \"Print Customers\", from the main menu.",
			"Help To Print All Customers.");
	helpMenu.add("To Print customers by name, select \"Print Customers By Name\", from the main menu",
			"Help To Print Customers By Name");
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


void Admin::ChangeCustomerInfo(){
	Node<CustomerType> *toChange;
	CustomerType		infoChange;
	std::string  		updateInfo;
	Interest 			aLevel;
	Desirable 			aDesire;
	char 				gotPamphlet;
	int 				anInput;
	int 				changeMenu;
	std::string 		changeName;
	bool 				found;
	std::string 		inName;

	printf("--Change Customer Info\n");
	inName = input::scanName();

	found = false;
	toChange = NULL;

	// PROCESSING - Call Search method to find customer
	found = customers.CustomerSearch(inName);

	if(found)
	{
		infoChange.SetName(inName);
		toChange = customers.Search(infoChange);

		changeMenu = input::scanIntPrompt("0 - Change Name\n"
				"1 - Change Address\n"
				"2 - Change City\n"
				"3 - Change State\n"
				"4 - Change Zip Code\n"
				"5 - Change Customer Interest Level\n"
				"6 - Change Company's Desire To Have Customer\n"
				"7 - Change If Pamphlet has been received\n"
				"Enter choice: ", "***Not a valid menu choice***\n", 0, 7);
		std::cin.ignore(1000,'\n');

		switch(changeMenu)
		{
		case 0  :	// PROCESSING - Call Search method to find customer
					do
					{
						updateInfo = input::scanName();
						found = customers.CustomerSearch(updateInfo);
						if(found)
						{
							cout << "Cannot Change name to " << updateInfo << endl;
						}
					}while(found);
					cout << "Changing name to " << updateInfo << endl;
					toChange->data.SetName(updateInfo);
					break;
		case 1  :	toChange->data.SetAddress(input::scanString("Enter Address: "));
					break;
		case 2  :	toChange->data.SetCity(input::scanString("Enter City: "));
					break;
		case 3  :	toChange->data.SetState(input::scanString("Enter State: "));
					break;
		case 4  :	toChange->data.SetZipCode(input::scanIntPrompt("Enter zip code: ", "***Not a valid zip code***", 0, 99999));
					break;
		case 5  :	anInput = input::scanIntPrompt("Customer's interest level in iRobotsTheBomb\n"
				"0 - Very Interested\n"
				"1 - Somewhat Interested\n"
				"2 - Not Interested\n"
				"3 - Never Call\n"
				"Enter Number: ", "***Invalid Customer Interest Level***\n", 0, 3);
					(anInput == 0) ? aLevel = VERY
							: (anInput == 1) ? aLevel = SOMEWHAT
									: (anInput == 2) ? aLevel = NO
											: (anInput == 3) ? aLevel = NEVER_CALL
													: aLevel = VERY;
					toChange->data.SetInterestLevel(aLevel);
					break;
		case 6  :	anInput = input::scanIntPrompt("iRobotsTheBomb desire to have Customer\n"
				"0 - Key Customer\n"
				"1 - Nice to Have Customer\n"
				"Enter Number: ", "***Invalid Desire Level\n***", 0, 1);
		(anInput == 0) ? aDesire = KEY : (anInput == 1) ? aDesire = NICE_TO_HAVE : aDesire = NICE_TO_HAVE;
		toChange->data.SetDesirability(aDesire);
					break;
		case 7  :	gotPamphlet = input::scanChar("Did the Customer receive a pamphlet? (y/n): ", "***Invalid Pamphlet Info***\n", 'Y', 'N');
					(gotPamphlet == 'Y') ? toChange->data.SetReceived(true) : toChange->data.SetReceived(false);
					break;
		default : 	break;
		}

	}
	customers.SaveAndOpenList("CustomerList.txt");
}
void Admin::CustomerSearch(){
	printf("--Customer Search\n");
	std::string inName = input::scanName();
	customers.CustomerSearch(inName);

}
void Admin::AddCustomer(){
	printf("--Add Customer\n");

	CustomerType	 aCust;
	char ans;
	do
	{
		customers.AddFromConsole();

		ans = input::scanChar("\nAdd another? (Y/N): ", "***Invalid Response***", 'Y', 'N');
		customers.PrintList();
	}while(ans != 'N');

	customers.SaveAndOpenList("CustomerList.txt");
	// cin customers?
}
void Admin::DeleteCustomer(){
	printf("--Delete\n");
	std::string inName = input::scanName();
	customers.DeleteACustomer(inName);

	customers.SaveAndOpenList("CustomerList.txt");
}
void Admin::SaveChanges(){
	printf("--Saving\n");

	customers.SaveList("CustomerList.txt");
	// customer.save
}
void Admin::PrintCustomers(){
	printf("--Printing\n");
	customers.PrintAllCustomerList();

	// customers.printAll()
}
void Admin::PrintCustomersByName(){
	printf("--PrintByName\n");
	std::string inName = input::scanName();
	customers.CustomerSearch(inName);
	// customers.lookup(inName);
}

void Admin::PrintKeyCustomers(){
	printf("--Printing Key Customers\n");
	customers.PrintKeyCustomerList();
}

void Admin::AddGuestToBeACustomer(){
	std::string fileName;
	printf("--Send Pamphlet to Guest\n"
		   "--Add Guest as a New Customer\n");
	fileName = "ProspectiveCustomerList.txt";
	customers.AddFromFileGuestToCust(fileName.c_str());

	customers.SaveAndOpenList("CustomerList.txt");
}
