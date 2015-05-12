// Guest.cpp

#include "Guest.h"


Guest::Guest() {
	initMenu();
}

Guest::~Guest(){

}

void Guest::initMenu(){
	menu.insert(static_cast<Pamphlet::fptr>( &Guest::RequestPamphlet ),	"Request Pamphlet");
	menu.insert(static_cast<Pamphlet::fptr>( &Guest::Help ), 			"Help");
}

void Guest::Help(){
	Menu<std::string> helpMenu("Guest Help Menu");
	std::string helpText;

	helpMenu.add("Exiting",
			"Exit Help Menu");
	helpMenu.add("To request a pamphlet, select \"Request Pamphlet\" option from the main menu.\nYou will need to provide information about yourself in order to order a pamphlet.",
			"Help requesting a pamphlet.");
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
void Guest::RequestPamphlet(){
	CustomerListType customers;
	CustomerType	 aCust;
	Login login;
	bool acctFail = true;

	printf("We require some information about you\n");
	//customers.AddFromFile("CustomerList.txt");	// handles looping
	ofstream outFile;
		bool 				invalid;
		int ratingNum;
		string prosName;
		string prosAddress;
		string prosCity;
		string prosState;
		int prosZipCode;
		string prosInterestLvl;

		// INPUT - Get Customer info: name, address, city, state
		cout << "Please enter your contact information so we can send "
				"you a pamphlet!\n";

		cout << "Enter Name: ";
		getline(cin, prosName);

		cout << "Enter Address: ";
		getline(cin, prosAddress);

		cout << "Enter City: ";
		getline(cin, prosCity);

		cout << "Enter State: ";
		getline(cin, prosState);

		// INPUT - Get Customer zip code and check validity - do until valid
		do
		{
			try
			{
				invalid = false;
				cout << "Enter Zip Code: ";
				if(!(cin  >> prosZipCode))
				{
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					throw prosZipCode;
				}
				else if(prosZipCode < 0 || prosZipCode > 99999)
				{
					throw prosZipCode;
				}
			}

			// OUTPUT - Tell user if not valid zip code
			catch(int caughtZipCode)
			{
				invalid = true;
				cout << "Invalid zip code: " << caughtZipCode << endl;
			}
		}while(invalid);

		// PROCESSING - Get interest level & check if valid - do until valid
		do
		{
			try
			{
				cout << "\nCustomer's interest level in iRobotsTheBomb\n"
						"0 - Very Interested\n"
						"1 - Somewhat Interested\n"
						"2 - Not Interested\n"
						"3 - Never Call\n"
						"Enter Number: ";

				// INPUT - Get input & check if valid
				if(!(cin >> ratingNum))
				{
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					throw ratingNum;
				}
				// PROCESSING - Check if valid choice
				else if(ratingNum < 0 || ratingNum > 3)
				{
					throw ratingNum;
				}
				else
				{
					// PROCESSING - Get interest level
					invalid = false;
					switch(ratingNum)
					{
						case 0	: 	prosInterestLvl = "very interested";
									break;
						case 1	: 	prosInterestLvl = "somewhat interested";
									break;
						case 2	: 	prosInterestLvl = "not interested";
									break;
						case 3	: 	prosInterestLvl = "never call";
									break;
						default	: 	break;
					}
				}
			}

			// OUTPUT - Tell user that interest level is not valid
			catch(int caughtInterest)
			{
				invalid = true;
				cout << "Invalid customer interest level: " << caughtInterest << endl;
			}
		}while(invalid);

		outFile.open("ProspectiveCustomerList.txt", std::ios_base::app);

		outFile << prosName << endl;
		cout << prosName << endl;
		outFile << prosAddress << endl;
		outFile << prosCity << endl;
		outFile << prosState << endl;
		outFile << prosZipCode << endl;
		outFile << prosInterestLvl << endl;

		outFile.close();
	printf("Thank you for your interest. A pamphlet will be sent to "
			"you shortly.\n");

	/*
	printf("Create a pamphlet account\n");
	login.InitializeInfo("LoginInfoTest.txt");
	while(acctFail){
		try{
			login.NewAccount("LoginInfoTest2.txt");
			acctFail = false;
		}
		catch(Login::UsernameTaken()){
			printf("User Name Is Taken\n");
		}
	}
	printf("Account Created! Restart Pamphlet to Login\n");
	*/
}

