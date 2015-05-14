
#include "CustomerListType.h"

/**************************************************************************
 * CONSTRUCTOR
 *************************************************************************/
CustomerListType::CustomerListType() {		}

/**************************************************************************
 * DESTRUCTOR
 *************************************************************************/
CustomerListType::~CustomerListType() {		}

/**************************************************************************
 * 							MUTATORS
 * ------------------------------------------------------------------------
 * 						AddFromConsole
 * 						AddFromFile
 * 						DeleteAllCustomer
 *************************************************************************/

/**************************************************************************
 * AddFromConsole
 * 		This method adds a Customer to the CustomerList from the console.
 * 		This method will get the following information: name,
 * 		address, city, state, zip code, whether the customer is
 * 		interested in the company, and the company's desire to have
 * 		this customer as a customer.
 *
 * 		Return: nothing (Adds customer to the list)
 *************************************************************************/
void CustomerListType::AddFromConsole()
{
	// Variable List
	Node<CustomerType> *currPtr;	// CALC		 - Customer Node
	CustomerType 		newNode;	// IN & CALC - Customer to add
	bool		 		found;		// CALC		 - Found Customer

	currPtr   = NULL;

	// INPUT - Get input about the Customer
	cin >> newNode;

	try
	{
		// PROCESSING - Search if the customer already exists
		SearchCustomerList(newNode.GetName(), found, currPtr);

		// PROCESSING - If Customer Exists throw
		if(found == true)
		{
			throw newNode.GetName();
		}
	}

	// OUTPUT - Tell user that this Customer already exists
	catch(string &caughtName)
	{
		cout << "Sorry this customer already exists: "
			 << newNode.GetName() << endl;
	}

	// PROCESSING - Add to the Customer list if name is unique
	if(!found)
	{
		AddNode(newNode);
	}
	else
	{
		cout << "Sorry this Customer could not be added\n";
	}
}

void CustomerListType::AddFromFileGuestToCust(string fileName)
{
	// Variable List
	Node<CustomerType> *currPtr;
	CustomerType 		newNode;		// CALC - Customer to add
	string       		addName;		// IN & CALC - Customer's name
	string    	 		addAddress;		// IN & CALC - Customer's address
	string    	 		addCity;		// IN & CALC - Customer's city
	string    	 		addState;		// IN & CALC - Customer's state
	int 	  	 		addZipCode;		// IN & CALC - Customer's zip code
	int			 		ratingNum;
	string 	  	 		anInterest;		// IN & CALC - Customer's interest
	string 	  	 		aDesire;		// IN & CALC - Company desire in customer
	Interest  	 		addInterest;	// CALC		 - Customer's interest
	Desirable 	 		addDesire;		// CALC		 - Company desire in customer
	ifstream	 		inFile;			// CALC		 - File input stream
	bool		 		validName;		// CALC		 - Valid input name
	bool		 		validDesire;	// CALC		 - Valid desire level
	bool		 		validInterest;	// CALC		 - Valid interest level
	bool		 		validZipCode;	// CALC		 - Valid zip code
	bool		 		invalidDesire;
	char		 		pamphlet;
	bool 				invalidPamphlet;
	bool 				gotPamphlet;

	inFile.open(fileName.c_str());

	// PROCESSING - Check if file exists or not
	if(inFile.fail())
	{
		cout << "Sorry, this file does not exist!\n";
	}
	else
	{
		if ( inFile.peek() == std::ifstream::traits_type::eof() )
		{
		    cout << fileName << " is empty\n";

		}
		else
		{
			// PROCESSING - Keep looping until end of file
			while(!inFile.eof())
			{
				currPtr		  = NULL;
				validName 	  = false;
				validDesire   = false;
				validInterest = false;
				validZipCode  = false;

				// INPUT - Get name
				getline(inFile, addName);

				if(addName != "" && addName != newNode.GetName())
				{
					// PROCESSING - Get name & search the list to see if unique
					SearchCustomerList(addName, validName, currPtr);

					// PROCESSING - Throw if name is not unique
					if(validName)
					{
						cout << "Sorry this Customer already exists: "
												 << addName << endl;
					}

					// INPUT - Get address, city, state
					getline(inFile, addAddress);
					getline(inFile, addCity);
					getline(inFile, addState);

					// INPUT - Get zip code
					try
					{
						// PROCESSING - Check if valid zip code or throw if not
						if(!(inFile >> addZipCode))
						{
							inFile.clear();
							inFile.ignore(numeric_limits<streamsize>::max(), '\n');
							throw addZipCode;
						}
						else if(addZipCode < 0 || addZipCode > 99999)
						{
							throw addZipCode;
						}
					}

					// OUTPUT - Tell user invalid zip code
					catch(int caughtZipCode)
					{
						validZipCode = false;
						cout << "Invalid zip code: " << caughtZipCode << endl;
					}

					// INPUT - Get desire level, interest level
					inFile.ignore(numeric_limits<streamsize>::max(), '\n');

					getline(inFile, anInterest);

					try
					{
						// PROCESSING - Get interest level
						if(anInterest == "very interested")
						{
							addInterest = VERY;
						}
						else if(anInterest == "somewhat interested")
						{
							addInterest = SOMEWHAT;
						}
						else if(anInterest == "not interested")
						{
							addInterest = NO;
						}
						else if(anInterest == "never call")
						{
							addInterest = NEVER_CALL;
						}
						else
						{
							throw anInterest;
						}
					}

					// OUTPUT - Tell user interest level is not valid
					catch(string &caughtInterest)
					{
						validInterest = false;
						cout << "Invalid interest level: " << caughtInterest << endl;
					}

					// PROCESSING - Get desire level until valid
					cout << left
						 << setw(NAME_COL)     << addName    << " "
						 << setw(ADDRESS_COL)  << addAddress << " "
						 << setw(CITY_COL)     << addCity    << " "
						 << setw(STATE_COL)    << addState   << " "
						 << setw(ZIPCODE_COL)  << addZipCode << " "
						 << setw(INTEREST_COL) << anInterest << endl
						 << right;
					do
					{
						try
						{
							cout << "\niRobotsTheBomb desire to have Customer\n"
									"0 - Key Customer\n"
									"1 - Nice to Have Customer\n"
									"Enter Number: ";

							// INPUT - Get desire level
							if(!(cin  >> ratingNum))
							{
								cin.clear();
								cin.ignore(numeric_limits<streamsize>::max(), '\n');
								throw ratingNum;
							}
							// PROCESSING - Check if menu choice is valid
							else if(ratingNum < 0 || ratingNum > 1)
							{
								throw ratingNum;
							}
							else
							{
								// PROCESSING - Get the correct desire level
								cin.ignore(numeric_limits<streamsize>::max(), '\n');
								invalidDesire = false;
								switch(ratingNum)
								{
									case 0	: 	addDesire = KEY;
												break;
									case 1	: 	addDesire = NICE_TO_HAVE;
												break;
									default	: 	break;
								}
							}
						}

						// OUTPUT - Tell user the desire level is not valid
						catch(int caughtDesireNum)
						{
							invalidDesire = true;
							cout << "Invalid Desire level to have Customer: " << caughtDesireNum << endl;
						}

					}while(invalidDesire);

					// PROCESSING - Get whether the pamphlet has been received - until valid
					do
					{
						try
						{
							// INPUT - Get received pamphlet or not (y/n)
							cout << "\nDid the Customer receive a pamphlet? (y/n): ";
							cin.get(pamphlet);
							cin.ignore(numeric_limits<streamsize>::max(), '\n');
							pamphlet = toupper(pamphlet);

							// PROCESSING - Check if invalid or not
							if(pamphlet != 'Y' && pamphlet != 'N')
							{
								throw pamphlet;
							}
							else
							{
								invalidPamphlet = false;

								// PROCESSING - Get boolean if valid
								(pamphlet == 'Y')   ? gotPamphlet = true
													: gotPamphlet = false;
							}
						}

						// OUTPUT - Tell user if pamphlet is not valid
						catch(char caughtReceived)
						{
							invalidPamphlet = true;
							cout << "Invalid information if pamphlet was received: " << caughtReceived << endl;
						}
					}while(invalidPamphlet);

						// PROCESSING - Add Customer to list
					newNode.SetValues(addName, addAddress, addCity, addState, addZipCode, addInterest, addDesire, gotPamphlet);
					AddNode(newNode);
					} // END IF
				} // END WHILE

			}

	} // END IF-ELSE


	inFile.close();

	inFile.open(fileName.c_str(), std::ifstream::out | std::ifstream::trunc );
	inFile.close();
}

/**************************************************************************
 * AddFromFile
 * 		This method adds Customers from a file to the Customer list.
 * 		The following information about a customer will be needed from
 * 		the file: the name, address, city, state, zip code, how interested
 * 		the customer is in the company, and how much the company desires
 * 		to have this customer as a customer.
 *
 * 		Return: nothing (Adds customer to the list)
 *************************************************************************/
void CustomerListType::AddFromFile(string fileName) // IN & CALC - File
{
	// Variable List
	Node<CustomerType> *currPtr;
	CustomerType newNode;		// CALC - Customer to add
	string       addName;		// IN & CALC - Customer's name
	string    	 addAddress;	// IN & CALC - Customer's address
	string    	 addCity;		// IN & CALC - Customer's city
	string    	 addState;		// IN & CALC - Customer's state
	int 	  	 addZipCode;	// IN & CALC - Customer's zip code
	string 	  	 anInterest;	// IN & CALC - Customer's interest
	string 	  	 aDesire;		// IN & CALC - Company desire in customer
	Interest  	 addInterest;	// CALC		 - Customer's interest
	Desirable 	 addDesire;		// CALC		 - Company desire in customer
	ifstream	 inFile;		// CALC		 - File input stream
	bool		 validName;		// CALC		 - Valid input name
	bool		 validDesire;	// CALC		 - Valid desire level
	bool		 validInterest;	// CALC		 - Valid interest level
	bool		 validZipCode;	// CALC		 - Valid zip code

	inFile.open(fileName.c_str());

	// PROCESSING - Check if file exists or not
	if(inFile.fail())
	{
		cout << "Sorry, this file does not exist!\n";
	}
	else
	{
		if ( inFile.peek() == std::ifstream::traits_type::eof() )
		{
		   cout << "File is empty\n";

		}
		else
		{
			// PROCESSING - Keep looping until end of file
			while(!inFile.eof())
			{
				currPtr		  = NULL;
				validName 	  = false;
				validDesire   = false;
				validInterest = false;
				validZipCode  = false;

				// INPUT - Get name
				getline(inFile, addName);

				if(addName != "")
				{
					// PROCESSING - Get name & search the list to see if unique
					SearchCustomerList(addName, validName, currPtr);

					// PROCESSING - Throw if name is not unique
					if(validName)
					{
						cout << "Sorry this Customer already exists: "
							 << addName << endl;
					}

					// INPUT - Get address, city, state
					getline(inFile, addAddress);
					getline(inFile, addCity, ',');
					inFile.ignore(1, '\n');
					getline(inFile, addState, ' ');

					// INPUT - Get zip code
					try
					{
						// PROCESSING - Check if valid zip code or throw if not
						if(!(inFile >> addZipCode))
						{
							inFile.clear();
							inFile.ignore(numeric_limits<streamsize>::max(), '\n');
							throw addZipCode;
						}
						else if(addZipCode < 0 || addZipCode > 99999)
						{
							throw addZipCode;
						}
					}

					// OUTPUT - Tell user invalid zip code
					catch(int caughtZipCode)
					{
						validZipCode = false;
						cout << "Invalid zip code: " << caughtZipCode << endl;
					}

					// INPUT - Get desire level, interest level
					inFile.ignore(numeric_limits<streamsize>::max(), '\n');
					getline(inFile, anInterest);
					getline(inFile, aDesire);

					try
					{
						// PROCESSING - Get interest level
						if(anInterest == "very interested")
						{
							addInterest = VERY;
						}
						else if(anInterest == "somewhat interested")
						{
							addInterest = SOMEWHAT;
						}
						else if(anInterest == "not interested")
						{
							addInterest = NO;
						}
						else if(anInterest == "never call")
						{
							addInterest = NEVER_CALL;
						}
						else
						{
							throw anInterest;
						}
					}

					// OUTPUT - Tell user interest level is not valid
					catch(string &caughtInterest)
					{
						validInterest = false;
						cout << "Invalid interest level: " << caughtInterest << endl;
					}

					try
					{
						// PROCESSING - Get desire level
						(aDesire == "key") ? addDesire = KEY
										   : (aDesire == "nice to have")
										   ? addDesire = NICE_TO_HAVE
										   : throw aDesire;
					}

					// OUTPUT - Tell user if desire is not valid
					catch(string &aDesire)
					{
						validDesire = false;
						cout << "Invalid Company Desire level to have Customer: "
							 << aDesire << endl;
					}

					// PROCESSING - Add customer if valid input
					if(addName != "" && !validName && !validInterest &&
					   !validDesire && !validZipCode)
					{
						newNode.SetName(addName);
						newNode.SetAddress(addAddress);
						newNode.SetCity(addCity);
						newNode.SetState(addState);
						newNode.SetZipCode(addZipCode);
						newNode.SetInterestLevel(addInterest);
						newNode.SetDesirability(addDesire);
						newNode.SetReceived(true);

						// PROCESSING - Add Customer to list
						AddNode(newNode);
					} // END IF
				} // END WHILE
			}
				}

	} // END IF-ELSE

	inFile.close();
}

void CustomerListType::ChangeCustomerInfo(string aName)
{
	Node<CustomerType> *toChange;
	bool				found;
	int 				changeMenu;
	string 				updateInfo;
	Interest 			aLevel;
	Desirable 			aDesire;
	char 				gotPamphlet;
	int 				anInput;

	found = false;

	// PROCESSING - Call Search method to find customer
	SearchCustomerList(aName, found, toChange);

	if(found)
	{
		changeMenu = input::scanIntPrompt("0 - Change Name\n"
				"1 - Change Address\n"
				"2 - Change City\n"
				"3 - Change State\n"
				"4 - Change Zip Code\n"
				"5 - Change Customer Interest Level\n"
				"6 - Change Company's Desire To Have Customer\n"
				"7 - Change If Pamphlet has been received\n"
				"Enter choice: ", "***Not a valid menu choice***\n", 0, 7);

		switch(changeMenu)
		{
		case 0  :	toChange->data.SetName(input::scanName());
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
	else
	{
		printf("Sorry this Customer does not exist\n");
	}
}

/**************************************************************************
 * DeleteACustomer
 * 		This method receives a name (string) that the user would like to
 * 		delete. This method will then loop and search through the list
 * 		until found or end of list. If the name is found then the Customer
 * 		will be deleted from the list. Otherwise the list will remain.
 *
 * 		Return: found (bool)
 *************************************************************************/
bool CustomerListType::DeleteACustomer(string aName) // IN - Name to delete
{
	// Variable List
	bool 				found;		// CALC & OUT - Deleted Customer
	Node<CustomerType> *toDelete;	// CALC 	  - Pointer to customer
	CustomerType		custInfo;	// CALC 	  - Customer info

	found = false;

	// PROCESSING - Call Search method to find customer
	SearchCustomerList(aName, found, toDelete);

	// PROCESSING - If found remove customer
	if(found)
	{
		custInfo = toDelete->data;
		RemoveNode(custInfo);
	}

	return found;
}

/**************************************************************************
 * 							ACCESSORS
 * ------------------------------------------------------------------------
 * 						CustomerSearch
 * 						PrintAllCustomerList
 * 						PrintKeyCustomerList
 * 						SaveList
 *************************************************************************/

/**************************************************************************
 * CustomerSearch
 * 		This method receives a name (string) that the user would like to
 * 		delete. This method will then loop and search through the list
 * 		until found or end of list. If the name is found then the Customer
 * 		will be deleted from the list. Otherwise the list will remain.
 *
 * 		Return: found (bool)
 *************************************************************************/
bool CustomerListType::CustomerSearch(string aName) const // IN - Find name
{
	// Variable List
	bool 				found;	// CALC & OUT - Found name
	Node<CustomerType> *toFind;	// CALC		  - Pointer to traverse list

	found = false;

	// PROCESSING - Find name in customer list
	SearchCustomerList(aName, found, toFind);

	// PROCESSING - If found display info or say customer does not exist
	if(found == true)
	{
		cout << "Found Customer:\n";
		toFind->data.Print();
		cout << endl;
	}
	else
	{
		cout << "Customer does not exist in system.\n";
	}
	return found;
}

/**************************************************************************
 * PrintAllCustomerList
 * 		This method prints all the customers in the customer list.
 * 		The following data includes: Name, address, city, state, zip code,
 * 		how interested the customer is in the company, how much the
 * 		company desires to have the customer, and whether or not the
 * 		pamphlet has been received.
 *
 * 		Return: nothing (Display list to console)
 *************************************************************************/
void CustomerListType::PrintAllCustomerList() const
{
	// Variable List
	Node<CustomerType> *tempNode; // CALC - Temp pointer in list

	tempNode = GetHead();

	// PROCESSING & OUTPUT - Loop through entire list & show customer info
	while(tempNode != NULL)
	{
		cout << tempNode->data;
		tempNode = tempNode->next;
	}

	cout << endl;
}

/**************************************************************************
 * PrintKeyCustomerList
 * 		This method prints all the key customers in the customer list.
 * 		The following data includes: Name, address, city, state, zip code,
 * 		how interested the customer is in the company, that the customer
 * 		is a key customer, & whether or not the pamphlet has been received.
 *
 * 		Return: nothing (Display list to console)
 *************************************************************************/
void CustomerListType::PrintKeyCustomerList() const
{
	// Variable List
	Node<CustomerType> *tempNode;	// CALC & OUT - Temp pointer to list

	tempNode = GetHead();

	// PROCESSING - Loops through entire list
	while(tempNode != NULL)
	{
		// PROCESSING - Check if Key customer & print info if so
		if(tempNode->data.GetDesirability() == KEY)
		{
			cout << tempNode->data;
		}

		tempNode = tempNode->next;
	}

	cout << endl;
}

/**************************************************************************
 * SaveList
 * 		This method saves the entire Customer list to a txt file.
 * 		The name of the file will be passed in. The following information
 * 		about a Customer will be saved to the file: name, address,
 * 		city, state, zip code, interest level in company, and company's
 * 		desire to have customer as a customer.
 *
 * 		Return: nothing (Saves customer to a txt file)
 *************************************************************************/
void CustomerListType::SaveList(string fileName) const
{
	// Variable List
	ofstream 			outFile;	// CALC - Output file stream
	Node<CustomerType> *tempNode;	// CALC & OUT - Temp ptr to list
	string 				anInterest;	// CALC & OUT - Interest level in co.
	string 				aDesire;	// CALC & OUT - Desire (key cust or not)

	tempNode = GetHead();

	outFile.open(fileName.c_str());

	// PROCESSING - Traverse through list until end
	while(tempNode != NULL)
	{
		// OUTPUT - Add information about customer to file (name,
		//		  - address, city, state, and zip code
		outFile << tempNode->data.GetName()    << endl
				<< tempNode->data.GetAddress() << endl
		 	 	<< tempNode->data.GetCity()    << ", "
				<< tempNode->data.GetState()   << " "
				<< tempNode->data.GetZipCode() << endl;

		// PROCESSING - Get interest level to output
		switch(tempNode->data.GetInterestLevel())
		{
			case VERY		: anInterest = "very interested";
							  break;
			case SOMEWHAT 	: anInterest = "somewhat interested";
							  break;
			case NO		  	: anInterest = "not interested";
							  break;
			case NEVER_CALL : anInterest = "never call";
							  break;
			default			: break;
		}

		// PROCESSING - Get desire level to output
		switch(tempNode->data.GetDesirability())
		{
			case KEY		  : aDesire = "key";
								break;
			case NICE_TO_HAVE : aDesire = "nice to have";
								break;
			default 		  :	break;
		}

		// OUTPUT - Add customer's interest level & company's desire
		//		  - to have customer to output file
		outFile << anInterest << endl
				<< aDesire    << endl;

		// PROCESSING - Get next customer in list
		tempNode = tempNode->next;
	}

	outFile.close();
}

/**************************************************************************
 * SearchCustomerList (PRIVATE METHOD)
 * 		This method receives a name (string), a boolean of whether or not
 * 		the customer is found, and the customer node (info). The customer
 * 		node and whether the customer is found will be passed back. This
 * 		method will check each member in the list until found or end of
 * 		the list.
 *
 * 		Return: found (bool) and currPtr (Node<CustoemrType>) (by ref)
 *************************************************************************/
void CustomerListType::SearchCustomerList(string 			  aName,
										  bool				  &found,
										  Node<CustomerType>* &currPtr) const
{
	// PROCESSING - Set variables
	found   = false;
	currPtr = GetHead();

	// PROCESSING - Keep looping through list until found or end of list
	while(currPtr != NULL && !found)
	{
		// PROCESSING - Check if name is the same else go to next in list
		if(currPtr->data.CheckName(aName))
		{
			found = true;
		}
		else
		{
			currPtr = currPtr->next;
		}
	}
}

void CustomerListType::SaveAndOpenList(string fileName)
{
	SaveList(fileName);
	ClearList();
	AddFromFile(fileName);
}
